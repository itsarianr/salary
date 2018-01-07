#include <iostream>
#include <locale>
using namespace std;

#define JOBS_COUNT 5
#define WORK_HOURS 160
#define QUIT_CODE -999

struct Job {
        char expertise[20];
        long int base_salary;
        long int overtime_salary;
        long int undertime_salary;
};

Job JOBS[JOBS_COUNT] = {
        {"Senior Engineer", 1000000, 5000, 6000},
        {"Simple Engineer", 800000, 4000, 5000},
        {"Technician", 600000, 3000, 4000},
        {"Expert Worker", 500000, 2500, 3000},
        {"Simple Worker", 460000, 2000, 2500}
};

long int calculate_salary(int row, int hours);

int main()
{
        while (true) {
                int code, row, hours;
                cout << "Enter employee's code: ";
                cin >> code;
                if (code == QUIT_CODE) {
                        cout << "Goodbye!\n";
                        return 0;
                }
                cout << "Enter row: ";
                cin >> row;
                if (row < 0 || row >= JOBS_COUNT) {
                        cout << "Row is out of range! Please try again.\n* * *\n";
                        continue;
                }
                cout << "Enter working hours: ";
                cin >> hours;
                cout.imbue(locale(""));
                cout << "Employee code: " << code << ", Salary: "
                     << calculate_salary(row, hours) << " IRR\n* * *\n";
        }
}

long int calculate_salary(int row, int hours) {
        Job job = JOBS[row];
        long int salary = job.base_salary;
        if (hours > WORK_HOURS) {
                int extra_hours = hours - WORK_HOURS;
                salary += extra_hours * job.overtime_salary;
        } else if (hours < WORK_HOURS) {
                int less_hours = WORK_HOURS - hours;
                salary -= less_hours * job.undertime_salary;
        }
        return salary;
}
