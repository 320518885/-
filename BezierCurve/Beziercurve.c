#include "Beziercurve.h"

#include <stdio.h>



/* USER CODE BEGIN PTD */
#define NUM_T_VALUES 50 // 定义 t 值的数量
#define NUM_P_VALUES 6   // 定义控制点的数量

// 控制点
float control_points[NUM_P_VALUES][2] = {
    {0.0f, 0.0f},
    {0.0f, 1.0f},
    {1.0f, 1.0f},
    {2.0f, 1.0f},
    {2.0f, 2.0f},
    {2.0f, 3.0f}
};

// 存储贝塞尔曲线上的路径点
float path_points[NUM_T_VALUES][2];

// 定义 t 值
float t_values[NUM_T_VALUES];

void bezier_curve(float control_points[][2], float t_values[], float path_points[][2]);
void BezierCurveCalculate(void) ;void bezier_curve(float control_points[][2], float t_values[], float path_points[][2]) {
    int i, j;

    // 计算贝塞尔曲线上的路径点
    for (i = 0; i < NUM_T_VALUES; i++) {
        float t = t_values[i];
        float p[NUM_P_VALUES][2]; // 临时存储控制点

        // 复制控制点到临时数组
        for (j = 0; j < NUM_P_VALUES; j++) {
            p[j][0] = control_points[j][0];
            p[j][1] = control_points[j][1];
        }

        // 使用递归计算贝塞尔曲线上的点
        for (int k = NUM_P_VALUES - 1; k > 0; k--) {
            for (j = 0; j < k; j++) {
                p[j][0] = (1 - t) * p[j][0] + t * p[j + 1][0];
                p[j][1] = (1 - t) * p[j][1] + t * p[j + 1][1];
            }
        }

        path_points[i][0] = p[0][0]; // 存储结果
        path_points[i][1] = p[0][1];
    }
}

void BezierCurveCalculate(void) {
    for (int i = 0; i < NUM_T_VALUES; i++) {
        t_values[i] = i / (float)(NUM_T_VALUES - 1); // 计算 t 值
    }

    // 计算贝塞尔曲线上的路径点
    bezier_curve(control_points, t_values, path_points);
}
