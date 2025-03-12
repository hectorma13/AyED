#ifndef SLL_NODET_H_
#define SLL_NODET_H_

#include <iostream>

template <class T> class sll_node_t {
public:
    sll_node_t() : data_{}, next_{nullptr} {}
    sll_node_t(const T& data) : data_{data}, next_{nullptr} {}
    ~sll_node_t() {};

    const T& get_data() const { return data_; }
    void set_data(const T& data) { data_ = data; }
    sll_node_t<T>* get_next() const { return next_; }
    void set_next(sll_node_t<T>* next) { next_ = next; }
    std::ostream& write(std::ostream& os = std::cout) const;

private:
    T data_;
    sll_node_t<T>* next_;
};

template <class T> std::ostream& sll_node_t<T>::write(std::ostream& os) const {
    os << data_;
    return os;
}

#endif  // SLL_NODET_H_
