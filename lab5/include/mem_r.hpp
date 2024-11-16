#pragma once
#include <iostream>
#include <map>
#include <memory>
#include <memory_resource>
#include <stdexcept>

class FixBlockM : public std::pmr::memory_resource {
  public:
    explicit FixBlockM(size_t totalSize)
        : _totalSize(totalSize), _memory(new char[totalSize]), _used(0) {}

    ~FixBlockM() {
        clear(); 
        delete[] _memory;
    }

  protected:
    void *do_allocate(size_t bytes, size_t alignment) override { //aligmnet - для выравнивания, проверка сколько байт. не можем написть- так наследуея от memory resource
        size_t offset =
            reinterpret_cast<std::uintptr_t>(_memory + _used) % alignment;
        if (offset != 0) {
            offset = alignment - offset;
        }

        size_t new_used = _used + offset + bytes;
        if (new_used > _totalSize) {
            throw std::bad_alloc(); 
        }

        void *result = _memory + _used + offset;
        _allocations[result] = bytes; 
        _used = new_used;
        return result;
    }

    void do_deallocate(void *ptr, size_t bytes, size_t alignment) override {
        auto it = _allocations.find(ptr);
        if (it == _allocations.end() || it->second != bytes) {
            throw std::invalid_argument("проблема на уровне деалокэйт, что то не так с рахмером или с блоком");
        }

        _allocations.erase(it);
        _freeBlocks.emplace_back(ptr,bytes); // Добавляем блок в список свободных
    }

    bool do_is_equal(//вроде не требуется само по зааданию, но должно туту быть, опять же потому что наследуемся от memory_resource, могут быть ошибки
        const std::pmr::memory_resource &other) const noexcept override {
        return this == &other;
    }

  private:
    void clear() {
        _allocations.clear();
        _freeBlocks.clear();
        _used = 0;
    }

    size_t _totalSize;
    char *_memory;
    size_t _used;

    std::map<void *, size_t>
        _allocations; // выделенные блоках
    std::vector<std::pair<void *, size_t>>
        _freeBlocks; // свободные блоков
};