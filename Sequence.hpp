
#pragma once
#include <iostream>

template<class T>

class Sequence {

    virtual T& GetFirst() const noexcept = 0;
    virtual T& GetLast() const noexcept = 0;
    virtual T& Get(int index) const = 0;
    virtual  Sequence<T>* GetSubsequence(int startIndex, int endIndex) = 0;
    virtual std:: size_t GetLength() const noexcept = 0;
    virtual  void Append(T& item) noexcept = 0;
    virtual  void Prepend(T& item) noexcept = 0;
    virtual  void Insert(T& item, int index) noexcept = 0;
    virtual  Sequence <T>* Concat(Sequence <T> *list) = 0;
    virtual  void del(std::size_t index) noexcept = 0;

    virtual ~Sequence() noexcept {}


};



