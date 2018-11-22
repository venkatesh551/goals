void m5(int x) {
    int y;
    y = 2;
    if (...) y = 1;
    foo(() -> x+y);
    // Illegal: y is not effectively final.
}

void m6(int x) {
    foo(() -> x+1);
    x++;
    // Illegal: x is not effectively final.
}

void m9(String[] arr) {
    for (String s : arr) {
        foo(() -> s);
        // Legal: s is effectively final
        // (it is a new variable on each iteration)
    }
}

void m10(String[] arr) {
    for (int i = 0; i < arr.length; i++) {
        foo(() -> arr[i]);
        // Illegal: i is not effectively final
        // (it is not final, and is incremented)
    }
}
