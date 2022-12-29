
#pragma once

#include <iostream>
#include "ArraySequence.hpp"



template<class T>

class IteratorArray{

public:
    IteratorArray() : elem(nullptr) {}
    IteratorArray(T* el) : elem(nullptr){
        elem = el;
    }



    IteratorArray<T>&  operator++ () override {
        ++CurrentInd;
        return IteratorArray(++elem);
    }
    T& operator*() override {
        return &elem;
    }
    IteratorArray<T>& operator-- () override {

        --CurrentInd;
        return IteratorArray(--elem);
    }
    bool operator==(IteratorArray<T> iter) override {
            return this == iter;
    }

    bool operator!=(IteratorArray<T> iter) override {
        return this != iter;
    }

    IteratorArray<T>& operator+= (std::size_t displacement) override {

            CurrentInd += displacement ;

        return IteratorArray(elem + displacement) ;
    }

    IteratorArray<T>& operator-= (std::size_t displacement) override {
        CurrentInd -= displacement ;

        return IteratorArray(elem - displacement) ;
        }


private:
    T* elem;
    std::size_t  CurrentInd;

};


