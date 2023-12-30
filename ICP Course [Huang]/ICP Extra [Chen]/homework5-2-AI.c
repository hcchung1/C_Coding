#include <stdio.h>

int main() {
    int m;
    scanf("%d", &m); // 1 <= m <= 100

    int nodes[m]; // Use m as the size of nodes array
    int numSets = 0;
    int setToMerge;
    int Mergetimes[101] = {0};
    

    for (int i = 0; i < m; i++) {
        nodes[i] = -1; // Initialize all nodes as -1 (unassigned)
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            int isConnected;
            scanf("%d", &isConnected);

            if (isConnected == 1) {
                if (nodes[i] == -1 && nodes[j] == -1) {
                    // Both nodes are unassigned, create a new set
                    numSets++;
                    nodes[i] = numSets;
                    nodes[j] = numSets;
                } else if (nodes[i] == -1) {
                    // Node i is unassigned, assign it to the same set as j
                    nodes[i] = nodes[j];
                } else if (nodes[j] == -1) {
                    // Node j is unassigned, assign it to the same set as i
                    nodes[j] = nodes[i];
                } else if (nodes[i] != nodes[j]) {
                    // Both nodes are assigned to different sets, merge them
                    setToMerge = nodes[j];
                    Mergetimes[setToMerge]++;
                    for (int k = 0; k < m; k++) {
                        if (nodes[k] == setToMerge) {
                            nodes[k] = nodes[i];
                        }
                    }
                }
            }
        }
    }

    for(int i = 0; i < m; i++) if(Mergetimes[i] != 0) numSets--;

    printf("%d\n", numSets);

    return 0;
}