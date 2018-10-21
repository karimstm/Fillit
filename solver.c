








int     **initial_table(int *counter)
{
     int **table = (int **)malloc(sizeof(int *) * (*counter));
     int i;
     int j;

     i = -1;
     while (++i < (*counter))
     {
         j = 0;
        while (j < (*counter))
            table[i][j++] = 0;
     }
     return (table);
}


int     solver(int **table, int *counter)
{
    int i;
    int j;

    table = initial_table(counter);


    return (0);
}
