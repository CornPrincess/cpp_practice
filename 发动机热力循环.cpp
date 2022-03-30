//
// Created by 周天斌 on 2022/3/12.
//

#include <iostream>
#include <math.h>

using namespace std;

double a(double H);
double b(double H);

int main() {
    cout << "你好，小阿敏,你又调皮了💗\n";
    // 飞行高度
    double H = 11;           //H = flight_height
    double XM = 1.6;          //XM = mach_number
    // 部件参数
    double B = 0.4;           //B = bypass_ratio
    double PI_fan = 3.8;      //PI_fan = pressure_ratio_fan
    double PI_hpc = 4.474;      //PI_hpc = pressure_ratio_hpc
    double PI_total = 17.0;    //PI_total = pressure_ratio_total
    double Tt4_DP = 1800;
    double Tt7 = 2000;
    // 部件效率
    double PI_intake_max = 0.97;   //PI_intake = intake_port_total_pressure_recovery_factor
    double effi_fan = 0.868;
    double effi_hpc = 0.878;
    double effi_comb = 0.98;
    double PI_comb = 0.97;     //PI_comb = comb_total_pressure_recovery_factor
    double effi_hpt = 0.89;
    double effi_lpt = 0.91;
    double PI_mixer = 0.97;     //PI_mixer= mix_chamber_total_pressure_recovery_factor
    double effi_att_comb = 0.97;
    double PI_att_comb = 0.97;      //PI_att_comb = att_comb_total_pressure_recovery_factor
    double PI_nozzle = 0.98; //PI_nozzle = nozzle_total_pressure_recovery_factor
    double mech_effi_HPSH = 0.98;
    double mech_effi_LPSH= 0.98;
    double mech_effi_PWX = 0.98;
    double k_air = 1.4;
    double cp_air = 1.005;
    double k_gas = 1.3;
    double cp_gas = 1.244;
    double R = 0.287;
    double fuel_LHV = 42900;
    double blex_hpt = 0.05;
    double blex_lpt = 0.05;
    double blex_cus = 0.01;

    cout << "请输入H（输入0表示保持默认值，当前默认值为 " << H << "）:" << endl;
    double temp;
    cin >> temp;
    if (temp != 0) {
        H = temp;
    }

    // 0-0 section
    double P0, T0;
    if (H <= 11) {
        T0 = 288.15 - 6.5 * H;
        P0 = 1.0133 * pow((1 - H /44.308), 5.2553) * pow(10, 5);
    } else  {
        T0 = 216.7;
        P0 = 0.227 * exp((11-H)/6.338);
    }
    double a0 , c0;
    a0 = sqrt(k_air * R * T0);
    c0 = a0 * XM;
    double Pt0 , Tt0;
    Pt0 = P0 * pow((1 + (k_air-1) / 2 * pow(XM,2)),(k_air /(k_air-1)));
    Tt0 = T0 * (1 + (k_air-1)/2 * pow(XM,2));

    //2-2 section
    double PI_intake;
    if(XM <= 1.0){
        PI_intake = PI_intake_max;
    }else{
        PI_intake = PI_intake_max * (1 - 0.075 * pow((XM-1),1.35));
    }
    double Pt2 , Tt2;
    Pt2 = PI_intake * Pt0;
    Tt2 = Tt0;

    //22-22
    double Pt22, Tt22, L_fan;
    Pt22 = PI_fan * Pt2;
    Tt22 = Tt2 * (1 + (pow(PI_fan,(k_air-1)/k_air)-1)/effi_fan);
    L_fan = cp_air * (Tt22- Tt2);

    //3-3
    double Pt3, Tt3, L_hpc;
    Pt3 = PI_hpc * Pt22;
    Tt3 = Tt22 * (1 + (pow(PI_hpc,(k_air-1)/k_air)-1)/effi_hpc);
    L_hpc = cp_air * (Tt3- Tt22);

    //4-4
    double Pt4, Tt4, far;
    Pt4 = PI_comb * Pt3;
    Tt4 = Tt4_DP;
    far = (cp_gas * Tt4 - cp_air * Tt3)/(effi_comb * fuel_LHV - cp_gas * Tt4);

    //45-45
    double Pt4a, Tt4a, Pt45, Tt45, Tt4aQ4, Tt45Q4a, c_blex1, PI_hpt;
    c_blex1 = (1-blex_cus-blex_hpt-blex_lpt)*(1+far);
    Tt4aQ4 = (c_blex1 + cp_air*blex_hpt*Tt3 / (cp_gas *Tt4))/(c_blex1+blex_hpt);
    Tt4a = Tt4aQ4 * Tt4;
    Pt4a = Pt4;
    Tt45Q4a = 1- cp_air*(Tt3-Tt22)/((c_blex1+blex_hpt)*mech_effi_HPSH*cp_gas*Tt4a);
    Tt45 = Tt45Q4a *Tt4a;
    PI_hpt = pow((1-(1-Tt45Q4a)/effi_hpt),(-k_gas/(k_gas-1)));
    Pt45 = PI_hpt * Pt4a;

    //5-5
    double Pt5, Tt5, Pt4c, Tt4c, Tt4cQ45, Tt5Q4c, PI_lpt;
    Tt4cQ45 = (c_blex1+blex_hpt+blex_lpt*cp_air*Tt3/(cp_gas*Tt45))/(c_blex1+blex_hpt+blex_lpt);
    Tt4c = Tt4cQ45 *Tt45;
    Pt4c =Pt45;
    Tt5Q4c = 1-((cp_air*(Tt22-Tt2)+ 3/mech_effi_PWX)*(1+B))/(effi_lpt*cp_gas*Tt4c*(c_blex1+blex_hpt+blex_lpt));
    Tt5 = Tt5Q4c * Tt4c;
    PI_lpt = pow((1-(1-Tt5Q4c)/effi_lpt),(-k_gas/(k_gas-1)));
    Pt5 = PI_lpt * Pt4c;


    //输出截面参数
    cout << "Pt0 = " << Pt0 << endl;
    cout << "Tt0 = " << Tt0 << endl;
    cout << "Pt2 = " << Pt2 << endl;
    cout << "Tt0 = " << Tt2 << endl;
    cout << "Pt22 = " << Pt22 << endl;
    cout << "Tt22 = " << Tt22 << endl;
    cout << "Pt3 = " << Pt3 << endl;
    cout << "Tt3 = " << Tt3 << endl;
    cout << "Pt4 = " << Pt4 << endl;
    cout << "Tt4 = " << Tt4 << endl;
    cout << "far = " << far << endl;
    //cout << "c_blex1 = " << c_blex1 << endl;
    //cout << "Tt4aQ4 = " << Tt4aQ4 << endl;
    cout << "Pt45 = " << Pt45 << endl;
    cout << "Tt45 = " << Tt45 << endl;
    cout << "PI_hpt = " << PI_hpt << endl;
    cout << "Pt5 = " << Pt5 << endl;
    cout << "Tt5 = " << Tt5 << endl;
    cout << "PI_lpt = " << PI_lpt << endl;

    //9-9
    double Pt9, Tt9;

    return 0;
}