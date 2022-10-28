// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
//

#ifndef __TDynamicMatrix_H__
#define __TDynamicMatrix_H__

#include <iostream>

using namespace std;

const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

// Динамический вектор - 
// шаблонный вектор на динамической памяти
template<typename T>
class TDynamicVector
{
protected:
  size_t sz;
  T* pMem;
public:
  TDynamicVector(size_t size = 1) : sz(size)
  {
    if ((sz == 0) || (sz > MAX_VECTOR_SIZE))
      throw invalid_argument("Vector size should be greater than zero. Also sz must be <= MAX_VECTOR_SIZE for test");
    pMem = new T[sz]();// {}; // У типа T д.б. констуктор по умолчанию
  }
  TDynamicVector(T* arr, size_t s) : sz(s)
  {
    assert(arr != nullptr && "TDynamicVector ctor requires non-nullptr arg");
    pMem = new T[sz];
    std::copy(arr, arr + sz, pMem);
  }
  TDynamicVector(const TDynamicVector& v)
  {
      this->sz = v.sz;
      this->pMem = new T[this->sz];
      for (int i = 0; i < this->sz; i++)
          this->pMem[i] = v.pMem[i];
  }
  TDynamicVector(TDynamicVector&& v) noexcept
  {
      this->pMem = nullptr;
      swap(*this, v);
  }
  ~TDynamicVector()
  {
      delete[] pMem;
  }
  TDynamicVector& operator=(const TDynamicVector& v)
  {
      if (this != &v)
          return *this;
  
      if (this->sz != v.sz)
      {
          TDynamicVector temp(v);
          swap(*this, temp);
          return *this;
      }
       
      for (int i = 0; i < this->sz; i++)
          this->pMem[i] = v.pMem[i];

      return *this;
  }

  TDynamicVector& operator=(TDynamicVector&& v) noexcept
  {
      swap(*this, v);
      return *this;
  }

  size_t size() const noexcept { return sz; }

  // индексация
  T& operator[](size_t ind)
  {
      return pMem[ind];
  }
  const T& operator[](size_t ind) const
  {
      return pMem[ind];
  }
  // индексация с контролем
  T& at(size_t ind)
  {
      if ((ind < 0) || (ind >= sz))
          throw out_of_range("Elements index must be greater or equal than zero or less than size of vector");

      return pMem[ind];
  }
  const T& at(size_t ind) const
  {
      if ((ind < 0) || (ind >= sz))
          throw out_of_range("Elements index must be greater or equal than zero or less than size of vector");

      return pMem[ind];
  }

  // сравнение
  bool operator==(const TDynamicVector& v) const noexcept
  {
      if (this->sz != v.sz)
          return false;
      for (int i = 0; i < this->sz; i++)
          if (this->pMem[i] != v.pMem[i])
              return false;

      return true;
  }
  bool operator!=(const TDynamicVector& v) const noexcept
  {
      return !(*this == v);
  }

  // скалярные операции
  TDynamicVector operator+(T val)
  {
      TDynamicVector temp(*this);
      for (int i = 0; i < temp.sz; i++)
        temp.pMem += val;

      return temp;
  }
  TDynamicVector operator-(T val)
  {
      TDynamicVector temp(*this);
      for (int i = 0; i < temp.sz; i++)
          temp.pMem -= val;

      return temp;
  }
  TDynamicVector operator*(T val)
  {
      TDynamicVector temp(*this);
      for (int i = 0; i < temp.sz; i++)
          temp.pMem[i] *= val;

      return temp;
  }

  // векторные операции
  TDynamicVector operator+(const TDynamicVector& v)
  {
      if (this->sz != v.sz)
          throw invalid_argument("Vectors must have equal sizes");

      TDynamicVector temp(*this);
      for (int i = 0; i < temp.sz; i++)
          temp.pMem[i] += v.pMem[i];
      return temp;
  }
  TDynamicVector operator-(const TDynamicVector& v)
  {
      if (this->sz != v.sz)
          throw invalid_argumet("Vectors must have equal sizes");

      TDynamicVector temp(*this);
      for (int i = 0; i < temp.sz; i++)
          temp.pMem[i] -= v.pMem[i];
      return temp;
  }
  T operator*(const TDynamicVector& v) noexcept(noexcept(T()))
  {
      T result = static_cast<T>(0);

      for (int i = 0; i < this->sz; i++)
          result += this->pMem[i] * v.pMem[i];

      return result;
  }

  friend void swap(TDynamicVector& lhs, TDynamicVector& rhs) noexcept
  {
    std::swap(lhs.sz, rhs.sz);
    std::swap(lhs.pMem, rhs.pMem);
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicVector& v)
  {
    for (size_t i = 0; i < v.sz; i++)
      istr >> v.pMem[i]; // требуется оператор>> для типа T
    return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicVector& v)
  {
    for (size_t i = 0; i < v.sz; i++)
      ostr << v.pMem[i] << ' '; // требуется оператор<< для типа T
    return ostr;
  }
};


// Динамическая матрица - 
// шаблонная матрица на динамической памяти
template<typename T>
class TDynamicMatrix : private TDynamicVector<TDynamicVector<T>>
{
  using TDynamicVector<TDynamicVector<T>>::pMem;
  using TDynamicVector<TDynamicVector<T>>::sz;
public:
  TDynamicMatrix(size_t s = 1) : TDynamicVector<TDynamicVector<T>>(s)
  {
    if (sz > MAX_MATRIX_SIZE)
        throw invalid_argument("For test");
    for (size_t i = 0; i < sz; i++)
      pMem[i] = TDynamicVector<T>(sz);
  }

  using TDynamicVector<TDynamicVector<T>>::operator[];

  // сравнение
  bool operator==(const TDynamicMatrix& m) const noexcept
  {
      return TDynamicVector<TDynamicVector<T>>::operator==(m);
  }

  // матрично-скалярные операции
  TDynamicVector<T> operator*(const T& val)
  {
      TDynamicMatrix temp(this->sz);
      for (int i = 0; i < temp.sz; i++)
          temp.pMem[i] = this->pMem[i] * val;

      return temp;
  }

  // матрично-векторные операции
  TDynamicVector<T> operator*(const TDynamicVector<T>& v)
  {
      TDynamicMatrix temp(this->sz);
      for (int i = 0; i < temp.sz; i++)
          temp.pMem[i] = this->pMem[i] * v;

      return temp;
  }

  // матрично-матричные операции
  TDynamicMatrix operator+(const TDynamicMatrix& m)
  {
      TDynamicMatrix temp(this->sz);
      for (int i = 0; i < temp.sz; i++)
          temp.pMem[i] = this->pMem[i] + m.pMem[i];

      return temp;
  }
  TDynamicMatrix operator-(const TDynamicMatrix& m)
  {
      TDynamicMatrix temp(this->sz);
      for (int i = 0; i < temp.sz; i++)
          temp.pMem[i] = this->pMem[i] - m.pMem[i];

      return temp;
  }
  TDynamicMatrix operator*(const TDynamicMatrix& m)
  {
      TDynamicMatrix temp(this->sz);
      for (int i = 0; i < temp.sz; i++)
          for (int j = 0; j < temp.sz; j++)
            temp.pMem[i][j] += this->pMem[i] * m.pMem[j];

      return temp;
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicMatrix& v)
  {
      for (int i = 0; i < v.sz; i++)
          for (int j = 0; j < v.sz; j++)
          {
              std::cout << "Enter " << i << " row, " << j << "column: ";
              istr >> v.pMem[i][j];
          }

      return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicMatrix& v)
  {
      for (int i = 0; i < v.sz; i++)
      {
          for (int j = 0; j < v.sz; j++)
          {
              ostr << v.pMem[i][j] << " ";
          }
          ostr << endl;
      }
      return ostr;
  }
};

#endif
