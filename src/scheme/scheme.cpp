// Dmytro Demchuk K-25

#include "scheme/scheme.hpp"

#include <latch>

#include "work/work.hpp"

namespace {

std::latch done_a{6};
std::latch done_b{5};
std::latch done_e{8};
std::latch done_g{4};
std::latch done_h{5};
std::latch done_i{6};
std::latch done_k{4};
std::latch done_c{8};
std::latch done_d{5};

}

void run(char x, int i) {
    switch (x) {
        case 'a': f(x, i); done_a.count_down(); break;
        case 'b': f(x, i); done_b.count_down(); break;
        case 'e': done_a.wait(); f(x, i); done_e.count_down(); break;
        case 'g': done_a.wait(); f(x, i); done_g.count_down(); break;
        case 'h': done_b.wait(); f(x, i); done_h.count_down(); break;
        case 'i': done_b.wait(); f(x, i); done_i.count_down(); break;
        case 'k': done_e.wait(); f(x, i); done_k.count_down(); break;
        case 'c': done_g.wait(); done_h.wait(); f(x, i); done_c.count_down(); break;
        case 'd': done_i.wait(); f(x, i); done_d.count_down(); break;
        case 'f': done_k.wait(); done_c.wait(); done_d.wait(); f(x, i); break;
    }
}
