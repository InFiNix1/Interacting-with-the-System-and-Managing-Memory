#include "cards.h"

int main(void) {
    card_t c = card_from_num(1);
    assert_card_valid(c);
    print_card(c);

    card_t c2 = card_from_letters('A', 'd');
    assert_card_valid(c2);
    print_card(c2);

}
