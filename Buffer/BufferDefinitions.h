#ifndef BUFFER_DEFINITIONS_H_
#define BUFFER_DEFINITIONS_H_

template <typename T>
struct Buffer {
    T*     data = NULL;
    size_t size = 0;
};

template <typename T> TypeOfError ReadFile              (Buffer<T>* buffer_struct, const char* filename);
template <typename T> TypeOfError ScanFileToBuffer      (Buffer<T>* buffer_struct, const char* filename);
template <          > TypeOfError ScanFileToBuffer<char>(Buffer<char>* buffer_struct, const char* filename);
TypeOfError                       GetSizeOfBuffer       (size_t* size, const char* filename);
template <typename T> size_t        CountLines            (Buffer<T>* buffer_struct, const char* filename);
template <          > size_t        CountLines<char>      (Buffer<char>* text, const char* filename);
template <typename T> TypeOfError BufferDtor            (Buffer<T>* buffer_struct);
template <          > TypeOfError BufferDtor<char>      (Buffer<char>* buffer_struct);
template <          > TypeOfError BufferDtor<char*>     (Buffer<char*>* buffer_struct);

#endif
