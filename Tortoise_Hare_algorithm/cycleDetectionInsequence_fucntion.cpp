int f(int n, int m) {
    return (n * n) % m;
}

bool hasCycleInFunction(int start, int m) {
    int slow = start, fast = f(start, m);
    while (slow != fast) {
        slow = f(slow, m);
        fast = f(f(fast, m), m);
    }
    return true;  // Cycle exists
}
