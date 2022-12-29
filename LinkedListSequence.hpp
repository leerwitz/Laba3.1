
#pragma once


#include <iostream>
#include "Sequence.hpp"
#include "LinkedList.hpp"


template <typename T>

class LinkedListSequence : public Sequence<T> {
private:
LinkedList<T>* arr;

public:
    LinkedListSequence() noexcept  : arr(new LinkedList<T>()) {};
    LinkedListSequence(T *item, std::size_t size) noexcept : arr(new LinkedListSequence<T>(item,size)){};
    ~LinkedListSequence() noexcept  {delete arr; }

public:

    T& GetFirst() const noexcept override { return  this->arr->GetFirst(); }

    T& GetLast() const noexcept override {return this->arr->GetLast(); }

    T& Get(int index) const override {return this->arr->Get(index); }

    Sequence<T>* GetSubsequence(int startIndex, int endIndex) override {return this->arr->GetSubList(startIndex,endIndex); }

    std:: size_t GetLength() const noexcept override {return this->arr->GetLength(); }

    void Append(T& item) noexcept override {this->arr->Append(item); }

    void Prepend(T& item) noexcept override { this->arr->Prepend(item); }

    void Insert(T& item, int index) noexcept override { this->arr->InsertAt(item, index); }

    Sequence <T>* Concat(Sequence <T> *list) override { this->arr->Concat(list); }

    void del(std::size_t index) noexcept override { this->arr->del(index); }

    //LinkedList<T>* getlink() const noexcept  override {}

    friend class LinkedList<T>;
    Elem<T>* Next(int ind) {
        Elem<T>* p = this->LinkFirst();
        for (int i = 0; i <= ind; ++i) {
            p = p->next;
        }
        return p;
    }

    Elem<T>* Prev(int ind) {
        Elem<T>* p = this->LinkFirst();
        for (int i = 0; i < ind - 1; ++i) {
            p = p->next;
        }
        return p;
    }
    Elem<T>* First() {return this->LinkFirst();}


};



