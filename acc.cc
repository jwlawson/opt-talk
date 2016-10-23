int accumulate(int *arr, int size, int initial) {
  for (int i = 0; i < size; ++i) {
    initial += arr[i];
  }
  return initial;
}
