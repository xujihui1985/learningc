#include <stdio.h>
#include "widget.h"
#include <assert.h>

int main(void) {
    int result = widget_ok(1, 1);
    assert(result == 1 && "the value of function is true");
    return 0;
}
