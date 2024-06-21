#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int average = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            average = round(
                (float) (image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen) / 3);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int Red, Green, Blue = 0;
    int sepiaRed, sepiaBlue, sepiaGreen = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            Red = round((float) image[i][j].rgbtBlue * .189 + image[i][j].rgbtRed * .393 +
                        image[i][j].rgbtGreen * .769);
            Green = round((float) image[i][j].rgbtBlue * .168 + image[i][j].rgbtRed * .349 +
                          image[i][j].rgbtGreen * .686);
            Blue = round((float) image[i][j].rgbtBlue * .131 + image[i][j].rgbtRed * .272 +
                         image[i][j].rgbtGreen * .534);
            sepiaRed = Red;
            sepiaBlue = Blue;
            sepiaGreen = Green;
            if (Red > 255)
            {
                sepiaRed = 255;
            }
            if (Blue > 255)
            {
                sepiaBlue = 255;
            }
            if (Green > 255)
            {
                sepiaGreen = 255;
            }
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int temp1, temp2, temp3 = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width / 2); j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int totalred = 0, totalgreen = 0, totalblue = 0;
            int count = 0;
            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    if (0 <= i + k && i + k < height && 0 <= l + j && l + j < width)
                    {
                        totalred = copy[i + k][j + l].rgbtRed + totalred;
                        totalblue = copy[i + k][j + l].rgbtBlue + totalblue;
                        totalgreen = copy[i + k][j + l].rgbtGreen + totalgreen;
                        count++;
                    }
                }
            }

            image[i][j].rgbtRed = round((float) totalred / count);
            image[i][j].rgbtBlue = round((float) totalblue / count);
            image[i][j].rgbtGreen = round((float) totalgreen / count);
        }
    }
}
