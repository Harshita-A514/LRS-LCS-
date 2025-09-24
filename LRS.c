int longestCommonSubsequence(char* X, char* Y) {
    int m = strlen(X);
    int n = strlen(Y);
    int mat[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                mat[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                mat[i][j] = mat[i - 1][j - 1] + 1;
            else
                mat[i][j] = (mat[i - 1][j] > mat[i][j - 1]) ? mat[i - 1][j]
                                                            : mat[i][j - 1];
        }
    }

    int index = mat[m][n];
    char lcs[index + 1];
    lcs[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        } else if (mat[i - 1][j] > mat[i][j - 1])
            i--;
        else
            j--;
    }

    return(mat[m][n]);
}