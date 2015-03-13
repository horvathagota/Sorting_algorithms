#ifndef ALGORITHMS_H
#define ALGORITHMS_H

extern SDL_Surface *screen;
extern TTF_Font *font;
extern TTF_Font *font2;
extern SDL_Surface *felirat;
extern SDL_Color piros;
extern SDL_Color zold;
extern SDL_Rect hova;
extern int comparison_value;
extern int swap_value;
extern int count;

/**
 * feliratokat kiíró függvény
 * @param s - a kiírandó szöveg
 * @param x - x koordináta
 * @param y - y koordináta
 * @param font - betűtípus
 * @param colour - szín
 */
void title(const char* s, int x, int y, TTF_Font *font, SDL_Color colour);

/**
 * Bubble sort
 * @param t - a rendezendõ tömbre mutató pointer
 * @param n - a tömb mérete
 */
template <typename T>
void bubble(T *t, int n) {
    title("BACK <", 10, 10, font, piros);
    title("to", 10, 30, font2, piros);
    title("the", 10, 38, font2, piros);
    title("BUBBLE SORT", 33, 31, font, piros);
    title("COMPARISONS:", 320, 10, font, piros);
    title("SWAPS:", 600, 10, font, piros);

    swap_value = 0;
    int j;
    for (int i = n-1; i > 0; --i){
        for (j = 0; j < i; ++j){
            if (t[j+1] < t[j]) {
                T temp = t[j+1];
                t[j+1] = t[j];
                t[j] = temp;
                ++swap_value;
            }
        }
    }
}

/**
 * Selection sort
 * @param t - a rendezendõ tömbre mutató pointer
 * @param n - a tömb mérete
 */
template <typename T>
void selection(T *t, int n) {
    title("BACK <", 10, 10, font, piros);
    title("to", 10, 30, font2, piros);
    title("the", 10, 38, font2, piros);
    title("SELECTION SORT", 33, 31, font, piros);
    title("COMPARISONS:", 320, 10, font, piros);
    title("SWAPS:", 600, 10, font, piros);

    swap_value = 0;
    int minindex;

    for (int i = 0; i < n-1; ++i) {
        minindex = i;
        for (int j = i+1; j < n; ++j){
            if (t[j] < t[minindex]){
                minindex = j;
            }
        }
        if (minindex != i) {
            T temp = t[i];
            t[i] = t[minindex];
            t[minindex] = temp;
            ++swap_value;
        }
    }
}

/**
 * Gnome sort
 * @param t - a rendezendõ tömbre mutató pointer
 * @param n - a tömb mérete
 */
template <typename T>
void gnome(T *t, int n) {
    title("BACK <", 10, 10, font, piros);
    title("to", 10, 30, font2, piros);
    title("the", 10, 38, font2, piros);
    title("GNOME SORT", 33, 31, font, piros);
    title("COMPARISONS:", 320, 10, font, piros);
    title("SWAPS:", 600, 10, font, piros);

    swap_value = 0;
    int i = 0;
    while (i < n) {
        if (i == 0 || t[i-1] <= t[i]) {
            i++;
        } else {
            T tmp = t[i-1];
            t[i-1] = t[i];
            t[i] = tmp;
            i--;
            ++swap_value;
        }
    }
}

/**
 * Insertion sort
 * @param t - a rendezendõ tömbre mutató pointer
 * @param n - a tömb mérete
 */
template<typename T>
void insertion(T *t, int n){
    title("BACK <", 10, 10, font, piros);
    title("to", 10, 30, font2, piros);
    title("the", 10, 38, font2, piros);
    title("INSERTION SORT", 33, 31, font, piros);
    title("COMPARISONS:", 320, 10, font, piros);
    title("SWAPS:", 600, 10, font, piros);

    swap_value = 0;
    int j;
    for(int i = 1; i < n; ++i){
        T temp = t[i];
        for(j = i-1; j >= 0 && temp < t[j]; --j){
            t[j+1] = t[j];
        }
        t[j+1] = temp;
        ++swap_value;
    }
}

/**
 * segédfüggvény a pancake sorthoz, ez végzi egy adott intervallum megfordítását
 * @param t - a tömbre mutató pointer, amin a mûveletet végezzük
 * @param eddig - egy index, ameddig meg kell fordítani a tömböt
 */
template <typename T>
void megfordit(T *t, int eddig){
    for(int i = 0; i < 159; ++i)
        t[i].setAnimation(false);

    for (int i = 0; i < eddig/2; ++i) {
        T temp = t[i];
        t[i] = t[eddig-1-i];
        t[eddig-1-i] = temp;
        ++swap_value;
    }

    for(int i = 0; i < 159; ++i)
        t[i].setAnimation(true);
}

/**
 * maximumkeresõ függvény
 * @param t - a tömb
 * @param n - a tömb mérete
 * @return - a maximum indexe
 */
template<typename T>
int maximum(T *t, int n){
    int max = 0;
    for(int i = 1; i < n; ++i){
        if(t[i] > t[max])
            max=i;
    }
    return max;
}

/**
 * Pancake sort
 * @param t - a rendezendõ tömbre mutató pointer
 * @param n - a tömb mérete
 */
template <typename T>
void pancake(T *t, int n){
    if(count == 0){
        title("BACK <", 10, 10, font, piros);
        title("to", 10, 30, font2, piros);
        title("the", 10, 38, font2, piros);
        title("PANCAKE SORT", 33, 31, font, piros);
        title("COMPARISONS:", 320, 10, font, piros);
        title("SWAPS:", 600, 10, font, piros);
        swap_value = 0;
    }
    count++;

    megfordit(t, maximum(t,n)+1);
    megfordit(t, n);
    if(n > 0)
        pancake(t, n-1);
}

/**
 * Shell sort
 * @param t - a rendezendõ tömbre mutató pointer
 * @param n - a tömb mérete
 */
template<typename T>
void shell(T *t, int n){
    title("BACK <", 10, 10, font, piros);
    title("to", 10, 30, font2, piros);
    title("the", 10, 38, font2, piros);
    title("SHELL SORT", 33, 31, font, piros);
    title("COMPARISONS:", 320, 10, font, piros);
    title("SWAPS:", 600, 10, font, piros);

    swap_value = 0;
    int j;
    for(int increment = n/2; increment > 0; increment /= 2){
        for(int i = increment; i < n; i++){
            T temp = t[i];
            for(j = i; j >= increment ; j-=increment){
                if(temp < t[j-increment]){
                    t[j] = t[j-increment];
                }
                else{
                    break;
                }
            }
        t[j] = temp;
        ++swap_value;
        }
    }
}

/**
 * Cocktail shaker sort
 * @param t - a rendezendõ tömbre mutató pointer
 * @param n - a tömb mérete
 */
template<typename T>
void cocktail(T *t, int n) {
    title("BACK <", 10, 10, font, piros);
    title("to", 10, 30, font2, piros);
    title("the", 10, 38, font2, piros);
    title("COCKTAIL SHAKER SORT", 33, 31, font, piros);
    title("COMPARISONS:", 320, 10, font, piros);
    title("SWAPS:", 600, 10, font, piros);

    swap_value = 0;

    for (int i = 0; i < n/2; i++) {
        bool swapped = false;
        for (int j = i; j < n-i-1; j++) {
            if (t[j-1] > t[j]) {
                T tmp = t[j];
                t[j] = t[j-1];
                t[j-1] = tmp;
                swapped = true;
                ++swap_value;
            }
        }
        for (int j = n-2-i; j > i; j--) {
            if (t[j] > t[j+1]) {
                T tmp = t[j];
                t[j] = t[j+1];
                t[j+1] = tmp;
                swapped = true;
                ++swap_value;
            }
        }
        if(!swapped)
            break;
    }
}

/**
 * Merge sort
 * @param t - a rendezendõ tömbre mutató pointer
 * @param lsst - a rendezendő résztömb utolsó eleme
 * @param first - a rendezendő résztömb első eleme, ez a függvény legelső hívásakor 0
 */
template<typename T>
void merge(T *t, int last, int first = 0){
    if(count == 0){
        title("BACK <", 10, 10, font, piros);
        title("to", 10, 30, font2, piros);
        title("the", 10, 38, font2, piros);
        title("MERGE SORT", 33, 31, font, piros);
        title("COMPARISONS:", 320, 10, font, piros);
        title("SWAPS:", 600, 10, font, piros);
        swap_value = 0;
    }
    count++;

    if (first < last){
        int m = (last+first)/2;
        merge(t, m, first);
        merge(t, last, m+1);
        mergehelper(t, first, m, last);
    }
}

/**
 * Segédfüggvény a merge sorthoz
 * @param t - a rendezendő tömbre mutató pointer
 * @param first - a rendezendő résztömb első eleme
 * @param mid - a rendezendő résztömb középső eleme
 * @param last - a rendezendő résztömb utolsó eleme
 */
template<typename T>
void mergehelper(T *t, int first, int mid, int last){
    int i, j, k;
    int n1 = mid - first + 1;
    int n2 =  last - mid;

    T L[n1], R[n2];

    for(i = 0; i < n1; i++)
        L[i] = t[first + i];
    for(j = 0; j < n2; j++)
        R[j] = t[mid + 1+ j];

    i = 0;
    j = 0;
    k = first;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            t[k] = L[i];
            i++;
        }
        else{
            t[k] = R[j];
            j++;
            ++swap_value;
        }
        k++;
    }

    while (i < n1){
        t[k] = L[i];
        i++;
        k++;
    }

    while (j < n2 - 1){
        t[k] = R[j];
        j++;
        k++;
    }
}

/**
 * Quick sort
 * @param t - a rendezendõ tömbre mutató pointer
 * @param n - a tömb mérete
 */
template<typename T>
void quick(T *t, int n){
    if(count == 0){
        title("BACK <", 10, 10, font, piros);
        title("to", 10, 30, font2, piros);
        title("the", 10, 38, font2, piros);
        title("QUICK SORT", 33, 31, font, piros);
        title("COMPARISONS:", 320, 10, font, piros);
        title("SWAPS:", 600, 10, font, piros);
        swap_value = 0;
    }
    count++;

    if (n < 2)
        return;
    T pivot = t[n / 2];
    T *l = t;
    T *r = t + n - 1;
    while (l <= r) {
        if (*l < pivot) {
            l++;
        }
        else if (*r > pivot) {
            r--;
        }
        else {
            T temp = *l;
            *l = *r;
            *r = temp;
            l++;
            r--;
            ++swap_value;
        }
    }
    quick(t, r - t + 1);
    quick(l, t + n - l);
}

/**
 * Heap sort
 * @param t - a rendezendõ tömbre mutató pointer
 * @param n - a tömb mérete
 */
template<typename T>
void heap(T *t, int n){
    title("BACK <", 10, 10, font, piros);
    title("to", 10, 30, font2, piros);
    title("the", 10, 38, font2, piros);
    title("HEAP SORT", 33, 31, font, piros);
    title("COMPARISONS:", 320, 10, font, piros);
    title("SWAPS:", 600, 10, font, piros);

    swap_value = 0;

    for (int i = (n/2 -1); i >= 0; --i){
        heaphelper(t, i, n-1);
    }

    for (int i = n-1; i >= 0; --i){
        T temp = t[i];
        t[i] = t[0];
        t[0] = temp;
        ++swap_value;
        heaphelper(t, 0, i-1);
    }
}

/**
 * segédfüggvény a heap sorthoz
 * @param t - a rendezendő tömbre mutató pointer
 * @param top - a legfelső elem indexe
 * @param bottom - az utolsó elem indexe, amin a műveletet végezzük
 */
template<typename T>
void heaphelper(T *t, int top, int bottom){
    int maxchild, child;
    while (top*2 < bottom){
        child = top * 2 + 1;
        if (child == bottom)
            maxchild = child;
        else{
            if (t[child+1] < t[child]){
                maxchild = child;
            }
            else{
                maxchild = child + 1;
            }
        }

        if (t[top] < t[maxchild]){
            T temp = t[top];
            t[top] = t[maxchild];
            t[maxchild] = temp;
            ++swap_value;
        }
        else
            return;

        top = maxchild;
     }
}

/**
 * Comb sort
 * @param t - a rendezendõ tömbre mutató pointer
 * @param n - a tömb mérete
 */
template<typename T>
void comb(T *t, int n){
    title("BACK <", 10, 10, font, piros);
    title("to", 10, 30, font2, piros);
    title("the", 10, 38, font2, piros);
    title("COMB SORT", 33, 31, font, piros);
    title("COMPARISONS:", 320, 10, font, piros);
    title("SWAPS:", 600, 10, font, piros);

    swap_value = 0;
    int gap = n;
    for (;;){
        gap = (gap * 10) / 13;
        if (gap == 9 || gap == 10)
            gap = 11;
        if (gap < 1)
            gap = 1;
        bool swapped = false;
        for (int i = 0; i < n - gap; i++) {
            int j = i + gap;
            if (t[i] > t[j]){
                T temp = t[i];
                t[i] = t[j];
                t[j] = temp;
                swapped = true;
                ++swap_value;
            }
        }
        if (gap == 1 && !swapped)
            break;
    }
}

/**
 * segédfüggvény a bogo sorthoz, megnézi, hogy rendezett-e a tömb
 * @param t - a vizsgálandó tömbre mutató pointer
 * @param n - a tömb mérete
 * return - igaz, ha a tömb rendezett, hamis, ha nem
 */
template<class T>
bool isSorted(T *t, int n){
    while (--n >= 1){
        if (t[n] < t[n - 1]){
            return false;
        }
    }
    return true;
}

/**
 * egy másik segédfüggvény a bogo sorthoz, illetve a rendezések elõtt is ez keveri meg a tömböt
 * @param t - a tömb, aminek az elemeit megkeveri
 * @param n - a tömb mérete
 */
template<typename T>
void shuffle(T *t, int n){
    for (int i = 0; i < n; ++i){
        T p = t[i];
        int temp = rand() % n;
        t[i] = t[temp];
        t[temp] = p;
        ++swap_value;
    }
}

/**
 * Bogo sort
 * @param t - a rendezendõ tömbre mutató pointer
 * @param n - a tömb mérete
 */
template<typename T>
void bogo(T *t, int n){
    title("BACK <", 10, 10, font, piros);
    title("to", 10, 30, font2, piros);
    title("the", 10, 38, font2, piros);
    title("BOGO SORT", 33, 31, font, piros);
    title("COMPARISONS:", 320, 10, font, piros);
    title("SWAPS:", 600, 10, font, piros);

    swap_value = 0;

    while (!isSorted(t, n)){
        shuffle(t, n);
    }
}


#endif // ALGORITHMS_H
