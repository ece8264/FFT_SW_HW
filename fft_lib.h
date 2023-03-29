#ifndef fft_lib_h

#define fft_lib_h

void permute(int *x);
void danielson_lanczos(int *x, int *W);
void swap(int *x,int *y);
void fill_up(int *x);
void print_x(int *x);

#endif