#include "Beziercurve.h"

#include <stdio.h>



/* USER CODE BEGIN PTD */
#define NUM_T_VALUES 50 // ���� t ֵ������
#define NUM_P_VALUES 6   // ������Ƶ������

// ���Ƶ�
float control_points[NUM_P_VALUES][2] = {
    {0.0f, 0.0f},
    {0.0f, 1.0f},
    {1.0f, 1.0f},
    {2.0f, 1.0f},
    {2.0f, 2.0f},
    {2.0f, 3.0f}
};

// �洢�����������ϵ�·����
float path_points[NUM_T_VALUES][2];

// ���� t ֵ
float t_values[NUM_T_VALUES];

void bezier_curve(float control_points[][2], float t_values[], float path_points[][2]);
void BezierCurveCalculate(void) ;void bezier_curve(float control_points[][2], float t_values[], float path_points[][2]) {
    int i, j;

    // ���㱴���������ϵ�·����
    for (i = 0; i < NUM_T_VALUES; i++) {
        float t = t_values[i];
        float p[NUM_P_VALUES][2]; // ��ʱ�洢���Ƶ�

        // ���ƿ��Ƶ㵽��ʱ����
        for (j = 0; j < NUM_P_VALUES; j++) {
            p[j][0] = control_points[j][0];
            p[j][1] = control_points[j][1];
        }

        // ʹ�õݹ���㱴���������ϵĵ�
        for (int k = NUM_P_VALUES - 1; k > 0; k--) {
            for (j = 0; j < k; j++) {
                p[j][0] = (1 - t) * p[j][0] + t * p[j + 1][0];
                p[j][1] = (1 - t) * p[j][1] + t * p[j + 1][1];
            }
        }

        path_points[i][0] = p[0][0]; // �洢���
        path_points[i][1] = p[0][1];
    }
}

void BezierCurveCalculate(void) {
    for (int i = 0; i < NUM_T_VALUES; i++) {
        t_values[i] = i / (float)(NUM_T_VALUES - 1); // ���� t ֵ
    }

    // ���㱴���������ϵ�·����
    bezier_curve(control_points, t_values, path_points);
}
