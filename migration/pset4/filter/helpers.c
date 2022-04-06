#include "helpers.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define BYTES_PER_PIXEL 3.0

// Convert image to grayscale ***************************************************************
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterates over each row of pixels
    for (int i = 0; i < height; i++)
    {
        // Iterates over each pixel
        for (int j = 0; j < width; j++)
        {
            // Computes the sum of each RGB value and finds its average
            int sum = image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed;
            int average = round(sum / BYTES_PER_PIXEL);

            // Assigns average value to each byte in pixel
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }

    return;
}

// Reflect image horizontally ***************************************************************
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    if (width % 2 != 0)
    {
        // Computes the center pixel of the bmp file
        int mid = width / 2;

        // Iterates over each row
        for (int i = 0; i < height; i++)
        {
            RGBTRIPLE temp;

            // Iterates over each pixel
            for (int j = (width - 1), k = 0; j >= 0; j--, k++)
            {
                // Quits iterating over row when central pixel found
                if (j == mid)
                {
                    break;
                }

                // Swaps pixels
                temp.rgbtBlue = image[i][j].rgbtBlue;
                temp.rgbtGreen = image[i][j].rgbtGreen;
                temp.rgbtRed = image[i][j].rgbtRed;

                image[i][j].rgbtBlue = image[i][k].rgbtBlue;
                image[i][j].rgbtGreen = image[i][k].rgbtGreen;
                image[i][j].rgbtRed = image[i][k].rgbtRed;

                image[i][k].rgbtBlue = temp.rgbtBlue;
                image[i][k].rgbtGreen = temp.rgbtGreen;
                image[i][k].rgbtRed = temp.rgbtRed;
            }
        }
    }

    else
    {
        // Computes the center pixel of the bmp file
        int mid = width / 2;

        // Iterates over each row
        for (int i = 0; i < height; i++)
        {
            RGBTRIPLE temp;

            // Iterates over each pixel
            for (int j = (width - 1), k = 0; j >= 0; j--, k++)
            {
                // Quits iterating over row when central pixel found
                if (j == mid - 1)
                {
                    break;
                }

                // Swaps pixels
                temp.rgbtBlue = image[i][j].rgbtBlue;
                temp.rgbtGreen = image[i][j].rgbtGreen;
                temp.rgbtRed = image[i][j].rgbtRed;

                image[i][j].rgbtBlue = image[i][k].rgbtBlue;
                image[i][j].rgbtGreen = image[i][k].rgbtGreen;
                image[i][j].rgbtRed = image[i][k].rgbtRed;

                image[i][k].rgbtBlue = temp.rgbtBlue;
                image[i][k].rgbtGreen = temp.rgbtGreen;
                image[i][k].rgbtRed = temp.rgbtRed;
            }
        }
    }

    return;
}

// Blur image ***************************************************************
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Makes a temporary array to store blurred values
    RGBTRIPLE image_copy[height][width];
    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < width; y++)
        {
            image_copy[x][y].rgbtBlue = 0x000000;
            image_copy[x][y].rgbtGreen = 0x000000;
            image_copy[x][y].rgbtRed = 0x000000;
        }
    }

    // Iterates through each row
    for (int i = 0, j = 0; i < height; i++, j = 0)
    {
        // Temporary rgb values
        int blue = 0, green = 0, red = 0;
        float count = 0.0;

        // Iterates through each colume
        for (; j < width; j++)
        {
            // Gets values of target pixel
            blue = image[i][j].rgbtBlue;
            green = image[i][j].rgbtGreen;
            red = image[i][j].rgbtRed;
            count++;

            // Checks for colume to left
            if (j - 1 >= 0)
            {
                // Gets target pixel's rgb values
                blue += image[i][j - 1].rgbtBlue;
                green += image[i][j - 1].rgbtGreen;
                red += image[i][j - 1].rgbtRed;
                count++;
            }

            // Checks for colume to right
            if (j + 1 < width)
            {
                // Gets target pixel's rgb values
                blue += image[i][j + 1].rgbtBlue;
                green += image[i][j + 1].rgbtGreen;
                red += image[i][j + 1].rgbtRed;
                count++;
            }

            /******Checks for top row*******/
            if (i - 1 >= 0)
            {
                // Gets target pixel's rgb value
                blue += image[i - 1][j].rgbtBlue;
                green += image[i - 1][j].rgbtGreen;
                red += image[i - 1][j].rgbtRed;
                count++;

                // Checks for colume to left
                if (j - 1 >= 0)
                {
                    // Gets target pixel's rgb values
                    blue += image[i - 1][j - 1].rgbtBlue;
                    green += image[i - 1][j - 1].rgbtGreen;
                    red += image[i - 1][j - 1].rgbtRed;
                    count++;
                }

                // Checks for colume to the right
                if (j + 1 < width)
                {
                    // Gets values
                    blue += image[i - 1][j + 1].rgbtBlue;
                    green += image[i - 1][j + 1].rgbtGreen;
                    red += image[i - 1][j + 1].rgbtRed;
                    count++;
                }
            }

            /*****Checks for bottom row*****/
            if (i + 1 < height)
            {
                // Gets target pixel's rgb value
                blue += image[i + 1][j].rgbtBlue;
                green += image[i + 1][j].rgbtGreen;
                red += image[i + 1][j].rgbtRed;
                count++;

                // Checks for colume to the left
                if (j - 1 >= 0)
                {
                    // Gets target pixel's rgb values
                    blue += image[i + 1][j - 1].rgbtBlue;
                    green += image[i + 1][j - 1].rgbtGreen;
                    red += image[i + 1][j - 1].rgbtRed;
                    count++;
                }

                // Checks for colume to the right
                if (j + 1 < width)
                {
                    // Gets values
                    blue += image[i + 1][j + 1].rgbtBlue;
                    green += image[i + 1][j + 1].rgbtGreen;
                    red += image[i + 1][j + 1].rgbtRed;
                    count++;
                }
            }

            // Finds average and initializes image_copy
            image_copy[i][j].rgbtBlue = round(blue / count);
            image_copy[i][j].rgbtGreen = round(green / count);
            image_copy[i][j].rgbtRed = round(red / count);

            // Reset
            blue = green = red = 0;
            count = 0.0;
        }
    }

    // Updates the image
    for (int a = 0; a < height; a++)
    {
        for (int b = 0; b < width; b++)
        {
            image[a][b].rgbtBlue = image_copy[a][b].rgbtBlue;
            image[a][b].rgbtGreen = image_copy[a][b].rgbtGreen;
            image[a][b].rgbtRed = image_copy[a][b].rgbtRed;
        }
    }

    return;
}

// Detect edges ***************************************************************
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Copy of image file
    RGBTRIPLE image_copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image_copy[i][j] = image[i][j];
        }
    }

    // Kernels
    int gx_kernel[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy_kernel[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    // Iterates through each row
    for (int i = 0, j = 0; i < height; i++, j = 0)
    {
        for (; j < width; j++)
        {
            // Temporary rgb values
            int gxblue = 0, gxgreen = 0, gxred = 0;
            int gyblue = 0, gygreen = 0, gyred = 0;

            int k = 1, l = 1;

            // Gets target rgb values for target row
            gxblue += image_copy[i][j].rgbtBlue * gx_kernel[k][l];
            gxgreen += image_copy[i][j].rgbtGreen * gx_kernel[k][l];
            gxred += image_copy[i][j].rgbtRed * gx_kernel[k][l];

            gyblue += image_copy[i][j].rgbtBlue * gy_kernel[k][l];
            gygreen += image_copy[i][j].rgbtGreen * gy_kernel[k][l];
            gyred += image_copy[i][j].rgbtRed * gy_kernel[k][l];

            // Checks colume to left of target row
            if (j - 1 >= 0)
            {
                gxblue += image_copy[i][j - 1].rgbtBlue * gx_kernel[k][l - 1];
                gxgreen += image_copy[i][j - 1].rgbtGreen * gx_kernel[k][l - 1];
                gxred += image_copy[i][j - 1].rgbtRed * gx_kernel[k][l - 1];

                gyblue += image_copy[i][j - 1].rgbtBlue * gy_kernel[k][l - 1];
                gygreen += image_copy[i][j - 1].rgbtGreen * gy_kernel[k][l - 1];
                gyred += image_copy[i][j - 1].rgbtRed * gy_kernel[k][l - 1];
            }

            // Checks colume to the rigth of target row
            if (j + 1 < width)
            {
                gxblue += image_copy[i][j + 1].rgbtBlue * gx_kernel[k][l + 1];
                gxgreen += image_copy[i][j + 1].rgbtGreen * gx_kernel[k][l + 1];
                gxred += image_copy[i][j + 1].rgbtRed * gx_kernel[k][l + 1];

                gyblue += image_copy[i][j + 1].rgbtBlue * gy_kernel[k][l + 1];
                gygreen += image_copy[i][j + 1].rgbtGreen * gy_kernel[k][l + 1];
                gyred += image_copy[i][j + 1].rgbtRed * gy_kernel[k][l + 1];
            }

            // Checks for top row
            if (i - 1 >= 0)
            {
                // Gets target rgb values for target row
                gxblue += image_copy[i - 1][j].rgbtBlue * gx_kernel[k - 1][l];
                gxgreen += image_copy[i - 1][j].rgbtGreen * gx_kernel[k - 1][l];
                gxred += image_copy[i - 1][j].rgbtRed * gx_kernel[k - 1][l];

                gyblue += image_copy[i - 1][j].rgbtBlue * gy_kernel[k - 1][l];
                gygreen += image_copy[i - 1][j].rgbtGreen * gy_kernel[k - 1][l];
                gyred += image_copy[i - 1][j].rgbtRed * gy_kernel[k - 1][l];

                // Checks for colume to the left
                if (j - 1 >= 0)
                {
                    gxblue += image_copy[i - 1][j - 1].rgbtBlue * gx_kernel[k - 1][l - 1];
                    gxgreen += image_copy[i - 1][j - 1].rgbtGreen * gx_kernel[k - 1][l - 1];
                    gxred += image_copy[i - 1][j - 1].rgbtRed * gx_kernel[k - 1][l - 1];

                    gyblue += image_copy[i - 1][j - 1].rgbtBlue * gy_kernel[k - 1][l - 1];
                    gygreen += image_copy[i - 1][j - 1].rgbtGreen * gy_kernel[k - 1][l - 1];
                    gyred += image_copy[i - 1][j - 1].rgbtRed * gy_kernel[k - 1][l - 1];
                }

                // Checks for colume to the right
                if (j + 1 < width)
                {
                    gxblue += image_copy[i - 1][j + 1].rgbtBlue * gx_kernel[k - 1][l + 1];
                    gxgreen += image_copy[i - 1][j + 1].rgbtGreen * gx_kernel[k - 1][l + 1];
                    gxred += image_copy[i - 1][j + 1].rgbtRed * gx_kernel[k - 1][l + 1];

                    gyblue += image_copy[i - 1][j + 1].rgbtBlue * gy_kernel[k - 1][l + 1];
                    gygreen += image_copy[i - 1][j + 1].rgbtGreen * gy_kernel[k - 1][l + 1];
                    gyred += image_copy[i - 1][j + 1].rgbtRed * gy_kernel[k - 1][l + 1];
                }
            }

            // Checks for bottom row
            if (i + 1 < height)
            {
                // Gets target rgb values for target row
                gxblue += image_copy[i + 1][j].rgbtBlue * gx_kernel[k + 1][l];
                gxgreen += image_copy[i + 1][j].rgbtGreen * gx_kernel[k + 1][l];
                gxred += image_copy[i + 1][j].rgbtRed * gx_kernel[k + 1][l];

                gyblue += image_copy[i + 1][j].rgbtBlue * gy_kernel[k + 1][l];
                gygreen += image_copy[i + 1][j].rgbtGreen * gy_kernel[k + 1][l];
                gyred += image_copy[i + 1][j].rgbtRed * gy_kernel[k + 1][l];

                // Checks for colume to the left
                if (j - 1 >= 0)
                {
                    gxblue += image_copy[i + 1][j - 1].rgbtBlue * gx_kernel[k + 1][l - 1];
                    gxgreen += image_copy[i + 1][j - 1].rgbtGreen * gx_kernel[k + 1][l - 1];
                    gxred += image_copy[i + 1][j - 1].rgbtRed * gx_kernel[k + 1][l - 1];

                    gyblue += image_copy[i + 1][j - 1].rgbtBlue * gy_kernel[k + 1][l - 1];
                    gygreen += image_copy[i + 1][j - 1].rgbtGreen * gy_kernel[k + 1][l - 1];
                    gyred += image_copy[i + 1][j - 1].rgbtRed * gy_kernel[k + 1][l - 1];
                }

                // Checks for colume to the right
                if (j + 1 < width)
                {
                    gxblue += image_copy[i + 1][j + 1].rgbtBlue * gx_kernel[k + 1][l + 1];
                    gxgreen += image_copy[i + 1][j + 1].rgbtGreen * gx_kernel[k + 1][l + 1];
                    gxred += image_copy[i + 1][j + 1].rgbtRed * gx_kernel[k + 1][l + 1];

                    gyblue += image_copy[i + 1][j + 1].rgbtBlue * gy_kernel[k + 1][l + 1];
                    gygreen += image_copy[i + 1][j + 1].rgbtGreen * gy_kernel[k + 1][l + 1];
                    gyred += image_copy[i + 1][j + 1].rgbtRed * gy_kernel[k + 1][l + 1];
                }
            }

            // Gets squares
            int blue_sqrt = round(sqrt(pow(gxblue, 2) + pow(gyblue, 2)));
            int green_sqrt = round(sqrt(pow(gxgreen, 2) + pow(gygreen, 2)));
            int red_sqrt = round(sqrt(pow(gxred, 2) + pow(gyred, 2)));

            if (blue_sqrt > 255)
            {
                blue_sqrt = 255;
            }
            if (blue_sqrt < 0)
            {
                blue_sqrt = 0;
            }

            if (green_sqrt > 255)
            {
                green_sqrt = 255;
            }
            if (green_sqrt < 0)
            {
                green_sqrt = 0;
            }

            if (red_sqrt > 255)
            {
                red_sqrt = 255;
            }
            if (red_sqrt < 0)
            {
                red_sqrt = 0;
            }

            // Assign pixels
            image[i][j].rgbtBlue = blue_sqrt;
            image[i][j].rgbtGreen = green_sqrt;
            image[i][j].rgbtRed = red_sqrt;
        }
    }

    return;
}