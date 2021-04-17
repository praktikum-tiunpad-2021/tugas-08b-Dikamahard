#pragma once

namespace strukdat {

namespace priority_queue {

/**
 * @brief Implementasi struct untuk elemen, harus ada isi dan prioritas elemen.
 */
template <typename T>
struct Element {
  T data;
  int prio;

  Element *next;
};

template <typename T>
using ElementPtr = Element<T> *;

/**
 * @brief implemetasi struct untuk queue.
 */
template <typename T>
struct Queue {
  ElementPtr<T> head;
  ElementPtr<T> tail;
};

/**
 * @brief membuat queue baru
 *
 * @return  queue kosong
 */
template <typename T>
Queue<T> new_queue() {
   Queue<T> q;

   q.head = nullptr;
   q.tail = nullptr;

  return q;
}

//  -------- FUNGSI BUATAN SENDIRI ------------  //
template <typename T>
bool empty(Queue<T> q){

  if(q.head == nullptr && q.tail == nullptr){
    return true;
  }else {
    return false;
  }
}

template <typename T>
void createElement(ElementPtr<T> &newElm,T value, int priority ){
  newElm = new Element<T>;
  newElm->data = value;
  newElm->prio = priority;
  newElm->next = nullptr;
}
//   -------- BATAS FUNGSI BUATAN -------------  //

/**
 * @brief memasukan data sesuai priority elemen.
 *
 * @param q         queue yang dipakai.
 * @param value     isi dari elemen.
 * @param priority  prioritas elemen yang menentukan urutan.
 */
template <typename T>
void enqueue(Queue<T> &q, const T &value, int priority) {

  ElementPtr<T> newElm;

  createElement(newElm, value, priority);
  
  ElementPtr<T> temp = q.head;
  ElementPtr<T> prev = nullptr;

  if(empty(q)){
    q.head = newElm;
    q.tail = newElm;
  }else {
    while(newElm->prio <= temp->prio){
      if(temp->next == nullptr)
      break;

      prev = temp;
      temp = temp->next;
    }

    if (temp == q.head && newElm->prio > temp->prio){         // insert first
      newElm->next = temp;
      q.head = newElm;
    }else if (temp == q.tail && newElm->prio < temp->prio){  // insert last
      temp->next = newElm;
      q.tail = newElm;
    }else {                                                  // insert mid
      prev->next = newElm;
      newElm->next = temp;
    }
  }
}

/**
 * @brief mengembalikan isi dari elemen head.
 *
 * @param q   queue yang dipakai.
 * @return    isi dari elemen head.
 */
template <typename T>
T top(const Queue<T> &q) {
  return q.head->data;
}

/**
 * @brief menghapus elemen head queue (First in first out).
 *
 * @param q   queue yang dipakai.
 */
template <typename T>
void dequeue(Queue<T> &q) {
  ElementPtr<T> del;

  if(empty(q)){
    del = nullptr;
  }else if(q.head->next == nullptr){
    del = q.head;
    q.head = nullptr;
    q.tail = nullptr;
  }else {
    del = q.head;
    q.head = q.head->next;
    del->next = nullptr;
  }

  delete(del);
}

}  // namespace priority_queue

}  // namespace strukdat
