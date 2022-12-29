
#pragma once

#include <iostream>
#include "Sequence.hpp"
#include "DynamicArray.hpp"

template<class T>

class ArraySequence : public  Sequence<T> {
public:

    ArraySequence() noexcept : arr(new DynamicArray<T>()) {};

    ArraySequence(T* items, std::size_t size, std::size_t capacity) noexcept : arr(new DynamicArray<T>(items,size,capacity)){};

    ~ArraySequence() noexcept  { delete arr; };

    ArraySequence(std::size_t size) noexcept :arr (new DynamicArray<T>(size)) {};

public:

    T& GetFirst() const noexcept override {return this->arr->get(0); }

    T& GetLast() const noexcept override {return this->arr->get(this->arr->getSize() - 1); }

    T& Get(int index) const {return this->arr->get(index); }

    std:: size_t GetLength() const noexcept override {return this->arr->getSize(); }

    void Insert(T& item, int index) noexcept override {
        std::size_t size = this->data->get_size();
        std::size_t capacity = this->data->get_capacity();
        if ( size == capacity ) this->arr->resize(2*capacity);
        for (int i = size - 1; i > index ; --i) { this->arr->set(i, this->arr->get(i - 1)); }
        this->arr->set(index, item);
        this->arr->setSize(++size);
    }

    void Append(T& item) noexcept override { this->Insert(item, this->arr->getSize()); }

    void Prepend(T& item) noexcept override { this->Insert(item, 0); }

    Sequence<T>* GetSubsequence(int startIndex, int endIndex) override {

        auto  newarr = new ArraySequence<T>(this->arr->getCapacity());
        for (int i =startIndex ; i <= this->endIndex; ++i) {newarr->arr->set(i, this->Get(i)); }
        return newarr;
    }

    Sequence <T>* Concat(Sequence <T> *list) noexcept override {
        std::size_t size1 = this->GetLength();
        std::size_t  size2 = list->GetLength();

        auto newarr = new ArraySequence<T>(this->arr->link(), size1 + size2 , size1 + size2);
        for (int i = 0; i < size2; ++i) {
            newarr->arr->set(size1 + i, list->Get(i));
        }
        return newarr;
    }

    void del(std::size_t index) noexcept override { this->arr->Del(index); }

    

private:
    DynamicArray <T>*  arr;

};



