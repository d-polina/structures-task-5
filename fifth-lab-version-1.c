// 1 вариант. Создать программу, которая будет отсортировывать элемнты с помощью методов вставками и выбора

#include <stdio.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int minIndex = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
        printf("\nИтерация %d: ", i+1);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
            if (k == i) {
                printf("  *   ");
            }
        }
        printf("\n");
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        printf("\n Итерация %d:\t", i);

        
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[j]);
            if (j < i) {
                if (j == i - 1) {
                    printf(" *  ");
                } else {
                    printf(" ");
                }
            }
        }

        printf("\n");
        
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && key < arr[j]) {
            for (int k = 0; k < n; k++) {
                if (k == j) {
                    printf("%d ", arr[k]);
                } else if (k == j+1) {
                    printf("%d ", arr[j]);
            } else {
                printf("%d ", arr[k]);
            }
        }

            printf("\nСравниваем %d и %d ", arr[j], key);

            printf("\n");
            
            arr[j+1] = arr[j];
            j--;
        }
        
        arr[j + 1] = key;
        
        printf("\n");
    }
}

int main() {
    int n;
    printf("\n Введите размер массива: ");
    scanf("%d", &n);
    int arr[n];
    printf("\n Введите элементы массива: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("\n Исходный массив: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int choice;
    printf("\nВарианты сортировки:\n");
    printf("\n1. Отсортировать массив методом прямого выбора\n");
    printf("\n2. Отсортировать массив методом прямой вставки\n");
    printf("\n Выберите опцию: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\n Исходный массив: ");
            for (int i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            selectionSort(arr, n);
            printf("\nОтсортированный массив выбором: \n");
            break;
        case 2:
            printf("\n Исходный массив: ");
            for (int i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            insertionSort(arr, n);
            printf("\nОтсортированный массив вставками: \n");
            break;
        default:
            printf("Неверный выбор");
            return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
