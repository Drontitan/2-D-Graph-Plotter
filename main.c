#include "pbPlots.c"
#include "supportLib.c"

#define points 100

void Trignometry()
{
    printf("Enter The Choice For Your Trigonometric Function :");
    printf("\n1.Sin Function \n2.Cos Function \n3.Tan Function  \n");
    int choice;
    scanf("%d", &choice);
    double x[points];
    double y[points];

    for (int i = 0; i < points; i++)
    {
        x[i] = i / 10.0 - 2.5;
        switch (choice)
        {
        case 1:
            y[i] = Sin(x[i]);
            break;
        case 2:
            y[i] = Cos(x[i]);
            break;
        case 3:
            y[i] = Tan(x[i]);
            break;
        default:
            printf("Enter A valid Choice!!! \n");
        }
    }

    RGBABitmapImageReference *imageRef = CreateRGBABitmapImageReference();
    DrawScatterPlot(imageRef, 800, 600, x, points, y, points);

    size_t length;
    double *pngdata = ConvertToPNG(&length, imageRef->image);
    // DeleteImage(imageRef->image);

    WriteToFile(pngdata, length, "Trigonometry.png");
}

void InverseTrigonometry()
{
    printf("Enter The Choice For Your Inverse Trigonometric Function :\n");
    printf("1.Sin inverse Function \n2.Cos inverse Function \n3.Tan inverse Function\n");
    int choice;
    scanf("%d", &choice);
    double x[points];
    double y[points];
    for (int i = 0; i < points; i++)
    {
        x[i] = i / 10.0 - 2.5;
        switch (choice)
        {
        case 1:
            y[i] = asin(x[i]);
            break;
        case 2:
            y[i] = acos(x[i]);
            break;
        case 3:
            y[i] = atan(x[i]);
            break;
        default:
            printf("Enter A valid Choice!!! \n");
        }
    }

    RGBABitmapImageReference *imageRef = CreateRGBABitmapImageReference();
    DrawScatterPlot(imageRef, 800, 600, x, points, y, points);

    size_t length;
    double *pngdata = ConvertToPNG(&length, imageRef->image);
    // DeleteImage(imageRef->image);

    WriteToFile(pngdata, length, "InverseTrigonometry.png");
}
void Parabola()
{
    printf("Enter The Choice For Your Trigonometric Function :");
    printf("\n1.Parabola symmetric to y axis +ve \n2.Parabola symmetric to y axis -ve \n3.Parabola symmetric to x axis +ve\n4.Parabola symmetric to x axis -ve\n");
    int choice;
    scanf("%d", &choice);

    double x[points];
    double y[points];

    for (int i = 0; i < points; i++)
    {
        // x[i] = i / 10.0 - 2.5;
        switch (choice)
        {
        case 1:
            x[i] = i / 4 - 12;
            y[i] = (pow(x[i], 2));
            break;
        case 2:
            x[i] = i / 4 - 12;
            y[i] = -(pow(x[i], 2));
            break;
        case 3:
            y[i] = i / 4 - 12;
            x[i] = (pow(y[i], 2));
            break;
        case 4:
            y[i] = i / 4 - 12;
            x[i] = -(pow(y[i], 2));
            break;

        default:
            printf("Enter A valid Choice!!! \n");
        }
    }

    RGBABitmapImageReference *imageRef = CreateRGBABitmapImageReference();
    DrawScatterPlot(imageRef, 800, 600, x, points, y, points);

    size_t length;
    double *pngdata = ConvertToPNG(&length, imageRef->image);
    // DeleteImage(imageRef->image);

    WriteToFile(pngdata, length, "Parabola.png");
}

void Linear()
{
    float slope, yintercept;
    printf("Enter The slope of a line :");
    scanf("%f", &slope);
    printf("Enter The y intercept of a line :");
    scanf("%f", &yintercept);
    double xs[points];
    double ys[points];
    for (int i = 0; i < points; i++)
    {
        xs[i] = i / 10.0 - 2.5;
        ys[i] = (slope * xs[i]) + yintercept;
    }

    RGBABitmapImageReference *imageRef = CreateRGBABitmapImageReference();
    DrawScatterPlot(imageRef, 800, 800, xs, points, ys, points);

    size_t length;
    double *pngdata = ConvertToPNG(&length, imageRef->image);
    // DeleteImage(imageRef->image);

    WriteToFile(pngdata, length, "Linear.png");

    // DeleteImage(canvasReference->image);
}

void Histogram()
{
    int N;
    printf("Enter the number of dataentry you want ");
    scanf("%d", &N);
    int value[N];
    int i, j, n, x;

    for (n = 0; n < N; ++n)
    {
        printf("Enter the frequency of the data- %d : ", n + 1);
        scanf("%d", &x);
        value[n] = x;
        printf("%d\n", value[n]);
    }
    printf("\n");

    // printf("          |\n");
    for (n = 0; n < N; ++n)
    {
        for (i = 1; i <= 1; i++)
        {
            if (i == 1)
                printf("Group-%1d   |", n + 1);
            else
                printf("          |");

            for (j = 1; j <= value[n]; ++j)
                printf("%c", (char)254u);
            if (i == 1)
                printf("(%d)\n", value[n]);
            else
                printf("\n");
        }
        printf("          |\n");
    }
}

int main()
{
    int choice;
    printf("\n1.Linear Graph \n2.Trignometric Graph \n3.Inverse Trignometric Graph \n4.Parabola Graph \n5.Histogram \n6.Exit!! \n");
    printf("Enter Your Choice : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        Linear();
        break;
    case 2:
        Trignometry();
        break;
    case 3:
        InverseTrigonometry();
        break;
    case 4:
        Parabola();
        break;
    case 5:
        Histogram();
        break;
    case 6:
        return 0;
    default:
        printf("Invalid Choice Please Try Again...");
    }

    return 0;
}
