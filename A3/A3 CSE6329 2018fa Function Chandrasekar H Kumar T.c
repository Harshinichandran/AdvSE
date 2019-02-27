//Correlate function for the main program
_Bool Correlate (int size, float ArrayOne[], float ArrayTwo[], float *pearsonCoefficient, float *correlationFlag)
{
    float mean_x = 0.0;
    float mean_y = 0.0;
    float x_sqr = 0.0;
    float y_sqr = 0.0;
    float xy = 0.0;
    float x[200],y[200];
    int i;

    for(i=0;i<size;i++)
    {
        mean_x = mean_x + ArrayOne[i];
        mean_y = mean_y + ArrayTwo[i];
    }

    mean_x = mean_x/size;
    mean_y = mean_y/size;

    for(i=0;i<size;i++)
    {
        x[i] = ArrayOne[i] - mean_x;
        y[i] = ArrayTwo[i] - mean_y;
        x_sqr += (x[i]*x[i])/size;
        y_sqr += (y[i]*y[i])/size;
        xy += (x[i]*y[i]);
    }

    *pearsonCoefficient = (xy) / sqrt ((size*x_sqr)*(size*y_sqr));

    if (*pearsonCoefficient >= 0.9 && *pearsonCoefficient <=1)
        *correlationFlag = 1.0;
    else if (*pearsonCoefficient >= -1 && *pearsonCoefficient <= -0.9 )
        *correlationFlag = -1.0;
    else
        *correlationFlag = 0;

    if (size > 0)
        return 1;
    else
        return 0;

}
