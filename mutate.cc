#include <algorithm>
#include <cstring>

void mutate_cpy(int const* input,
                int* output,
                int k,
                int num_cols_,
                int num_rows_) {
  int const* k_row = input + k * num_cols_;
  std::memcpy(output, input, num_cols_ * num_rows_ * sizeof(int));

  int index = 0;
  for (int i = 0; i < num_rows_; ++i) {
    if (i == k) {
      for (int j = 0; j < num_cols_; ++j, ++index) {
        output[index] = -output[index];
      }
    } else if (k_row[i] < 0) {
      for (int j = 0; j < k; ++j, ++index) {
        if (k_row[j] > 0) {
          output[index] -= k_row[i] * k_row[j];
        }
      }
      output[index] = -output[index];
      ++index;
      for (int j = k + 1; j < num_cols_; ++j, ++index) {
        if (k_row[j] > 0) {
          output[index] -= k_row[i] * k_row[j];
        }
      }
    } else if (k_row[i] > 0) {
      for (int j = 0; j < k; ++j, ++index) {
        if (k_row[j] < 0) {
          output[index] += k_row[i] * k_row[j];
        }
      }
      output[index] = -output[index];
      ++index;
      for (int j = k + 1; j < num_cols_; ++j, ++index) {
        if (k_row[j] < 0) {
          output[index] += k_row[i] * k_row[j];
        }
      }
		} else {
			index += num_cols_;
    }
  }
}
void mutate_unrl(int const* input,
                int* output,
                int k,
                int num_cols_,
                int num_rows_) {
  int const* k_row = input + k * num_cols_;
  std::memcpy(output, input, num_cols_ * num_rows_ * sizeof(int));

	int index = 0;
	for (int i = 0; i < k; ++i) {
		if (k_row[i] < 0) {
			for (int j = 0; j < k; ++j, ++index) {
				if (k_row[j] > 0) {
					output[index] -= k_row[i] * k_row[j];
				}
			}
			output[index] = -output[index];
			++index;
			for (int j = k + 1; j < num_cols_; ++j, ++index) {
				if (k_row[j] > 0) {
					output[index] -= k_row[i] * k_row[j];
				}
			}
		} else if (k_row[i] > 0) {
			for (int j = 0; j < k; ++j, ++index) {
				if (k_row[j] < 0) {
					output[index] += k_row[i] * k_row[j];
				}
			}
			output[index] = -output[index];
			++index;
			for (int j = k + 1; j < num_cols_; ++j, ++index) {
				if (k_row[j] < 0) {
					output[index] += k_row[i] * k_row[j];
				}
			}
		}
	}
	for (int j = 0; j < num_cols_; ++j, ++index) {
		output[index] = -output[index];
	}
	for (int i = k + 1; i < num_rows_; ++i) {
		if (k_row[i] < 0) {
			for (int j = 0; j < k; ++j, ++index) {
				if (k_row[j] > 0) {
					output[index] -= k_row[i] * k_row[j];
				}
			}
			output[index] = -output[index];
			++index;
			for (int j = k + 1; j < num_cols_; ++j, ++index) {
				if (k_row[j] > 0) {
					output[index] -= k_row[i] * k_row[j];
				}
			}
		} else if (k_row[i] > 0) {
			for (int j = 0; j < k; ++j, ++index) {
				if (k_row[j] < 0) {
					output[index] += k_row[i] * k_row[j];
				}
			}
			output[index] = -output[index];
			++index;
			for (int j = k + 1; j < num_cols_; ++j, ++index) {
				if (k_row[j] < 0) {
					output[index] += k_row[i] * k_row[j];
				}
			}
		} else {
			index += num_cols_;
		}
	}
}
void mutate_avx(int const* input,
                int* output,
                int k,
                int num_cols_,
                int num_rows_) {
  int const* k_row = input + k * num_cols_;

  int index = 0;
  for (int i = 0; i < num_rows_; ++i) {
    if (i == k) {
      for (int j = 0; j < num_cols_; ++j, ++index) {
        output[index] = -input[index];
      }
    } else if (k_row[i] < 0) {
      for (int j = 0; j < num_cols_; ++j, ++index) {
        if (k_row[j] > 0) {
          output[index] = input[index] - k_row[i] * k_row[j];
        } else {
          output[index] = input[index];
        }
      }
    } else if (k_row[i] > 0) {
      for (int j = 0; j < num_cols_; ++j, ++index) {
        if (k_row[j] < 0) {
          output[index] = input[index] + k_row[i] * k_row[j];
        } else {
          output[index] = input[index];
        }
      }
    } else {
      for (int j = 0; j < num_cols_; ++j, ++index) {
        output[index] = input[index];
      }
    }
  }
  for (int i = 0; i < k; ++i) {
    output[k + i * num_cols_] = -input[k + i * num_cols_];
  }
  for (int i = k + 1; i < num_rows_; ++i) {
    output[k + i * num_cols_] = -input[k + i * num_cols_];
  }
}

void mutate_single(int const* input,
                   int* output,
                   int k,
                   int num_cols_,
                   int num_rows_) {
  int const* k_row = input + k * num_cols_;

  int index = 0;
  for (int i = 0; i < num_rows_; ++i) {
    for (int j = 0; j < num_cols_; ++j, ++index) {
      if (i == k || j == k) {
        output[index] = -input[index];
      } else {
        output[index] =
            input[index] +
            (k_row[i] < 0 ? -1 : 1) * std::min(k_row[i] * k_row[j], 0);
      }
    }
  }
}
