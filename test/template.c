#template Arr T
typedef struct {
    T *data;
    int len;
} Arr;
#end

int main() {
    Arr<int> a;
    Arr<int> b;
}
