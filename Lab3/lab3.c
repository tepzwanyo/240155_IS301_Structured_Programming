#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *inFile, *outFile;

    int empNo, dept, hoursWorked;
    float payRate, basePay;
    char exempt;

    // Open input file         
    if (outFile == NULL) {
        printf("Error creating payroll_register.txt\n");
        fclose(inFile);
        return 1;
    }

    // Skip the header line
    char header[100];
    fgets(header, sizeof(header), inFile);

    // Write header to output file
    fprintf(outFile, "%-10s %-10s %-10s %-10s %-15s %-10s\n",
            "EmpNo", "Dept", "PayRate", "Exempt", "HoursWorked", "BasePay");

    // Read data and process
    while (fscanf(inFile, "%d %d %f %c %d",
                  &empNo, &dept, &payRate, &exempt, &hoursWorked) == 5) {

        // Calculate base pay
        basePay = payRate * hoursWorked;

        // Write to output file
        fprintf(outFile, "%-10d %-10d %-10.2f %-10c %-15d %-10.2f\n",
                empNo, dept, payRate, exempt, hoursWorked, basePay);
    }

    // Close files
    fclose(inFile);
    fclose(outFile);

    printf("Payroll register has been created.\n");

    return 0;
}
