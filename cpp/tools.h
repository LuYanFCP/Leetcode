
/**
 * 用作Leetcode 测试用的宏
 * 
 * 测试容器
 * + PRINT_VRECTOR 用于打印整个线性容器的一个宏 （之后可以会拓展支持数组）
 * + PRINT_MATRIX  用于打印二阶vec的宏 (现在只能使用vec， 之后可能扩展为arr)
*/

#define PRINT_VECTOR(vec, type, io_obj) \
do { \
    copy(vec.begin(), vec.end(), ostream_iterator<type>(io_obj, " ")); \
    cout << endl; \
} while(0)

#define PRINT_MATRIX(matrix, type, io_obj) \
do { \
    for (auto &vec: matrix) {\
        PRINT_VECTOR(vec, type, io_obj); \
    } \
} while(0)


#define CHANGE_()