#include <stdio.h>

int main() {
    int c[20][20], i, k, j, m, n, dem[20], sup[20], sum = 0, al[20][20];

    printf("\nEnter the number of rows and columns: ");
    scanf("%d%d", &m, &n);

    // Initialize allocation matrix to 0
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            al[i][j] = 0;
        }
    }

    printf("\nEnter the cost matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &c[i][j]);
        }
    }

    printf("\nEnter the demand array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &dem[i]);
    }

    printf("\nEnter the supply array:\n");
    for (i = 0; i < m; i++) {
        scanf("%d", &sup[i]);
    }

    printf("\nMatrix:\n\n +");
    for (i = 0; i < n; i++) {
        printf("------+");
    }
    printf("\n ");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("| %d ", c[i][j]);
        }
        printf("| %d \n +", sup[i]);
        for (k = 0; k < n; k++) {
            printf("------+");
        }
        printf("\n ");
    }

    for (j = 0; j < n; j++) {
        printf(" %d ", dem[j]);
    }

    // Northwest Corner Method
    for (i = 0, j = 0; (i < m && j < n); ) {
        if (sup[i] < dem[j]) {
            sum += c[i][j] * sup[i];
            al[i][j] = sup[i];
            dem[j] -= sup[i];
            sup[i] = 0;
            i++;
        } else if (sup[i] > dem[j]) {
            sum += c[i][j] * dem[j];
            al[i][j] = dem[j];
            sup[i] -= dem[j];
            dem[j] = 0;
            j++;
        } else { // when sup[i] == dem[j]
            sum += c[i][j] * dem[j];
            al[i][j] = dem[j];
            sup[i] = 0;
            dem[j] = 0;
            j++;
            i++;
        }
    }

    printf("\n\nAllocation Matrix:\n +");
    for (i = 0; i < n; i++) {
        printf("-----+");
    }
    printf("\n ");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("| %d ", al[i][j]);
        }
        printf("|\n +");
        for (k = 0; k < n; k++) {
            printf("-----+");
        }
        printf("\n ");
    }

    printf("\n\nFeasible Solution = %d\n", sum);

    return 0;
}
