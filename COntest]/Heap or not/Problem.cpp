string isMinHeap(int A[], int N) {
    for (int i = 0; i <= (N - 2) / 2; ++i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < N && A[i] > A[left]) {
            return "No";
        }
        if (right < N && A[i] > A[right]) {
            return "No";
        }
    }
    return "Yes";
}