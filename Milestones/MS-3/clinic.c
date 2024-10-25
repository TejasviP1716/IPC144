/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
Full Name  : Tejasvi Parmar
Section    : ZDD

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"

//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
        "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
            "Number: %05d\n"
            "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
            patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
            "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
            "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
    const struct Appointment* appoint,
    int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
            appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.minute,
        patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
            "=========================\n"
            "1) PATIENT     Management\n"
            "2) APPOINTMENT Management\n"
            "-------------------------\n"
            "0) Exit System\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            menuAppointment(data);
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
            "=========================\n"
            "1) VIEW   Patient Data\n"
            "2) SEARCH Patients\n"
            "3) ADD    Patient\n"
            "4) EDIT   Patient\n"
            "5) REMOVE Patient\n"
            "-------------------------\n"
            "0) Previous menu\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
            "=========================\n"
            "1) NAME : %s\n"
            "2) PHONE: ", patient->patientNumber, patient->name);

        displayFormattedPhone(patient->phone.number);

        printf("\n"
            "-------------------------\n"
            "0) Previous menu\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
            "==============================\n"
            "1) VIEW   ALL Appointments\n"
            "2) VIEW   Appointments by DATE\n"
            "3) ADD    Appointment\n"
            "4) REMOVE Appointment\n"
            "------------------------------\n"
            "0) Previous menu\n"
            "------------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------



// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (Copy your code from MS#2)
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int i, find = 0;

    displayPatientTableHeader();
    for (i = 0; i < max; i++)
    {
        if (!(patient[i].patientNumber) == 0)
        {
            displayPatientData(&patient[i], fmt);
            find = 1;
        }
    }
    if (!find)
    {
        printf("*** No records found ***\n");
    }
    printf("\n");
}

// Search for a patient record based on patient number or phone number
// (Copy your code from MS#2)
void searchPatientData(const struct Patient patient[], int max)
{
    int selection;
    do {
        printf("Search Options\n"
            "==========================\n"
            "1) By patient number\n"
            "2) By phone number\n"
            "..........................\n"
            "0) Previous menu\n"
            "..........................\n");
        printf("Selection: ");
        selection = inputIntRange(0, 2);
        printf("\n");
        if (selection == 2)
        {
            searchPatientByPhoneNumber(patient, max);
            suspend();
        }
        else if (selection == 1)
        {
            searchPatientByPatientNumber(patient, max);
            suspend();
        }
    } while (selection);
}

// Add a new patient record to the patient array
// (Copy your code from MS#2)
void addPatient(struct Patient patient[], int max)
{
    int i, addPatient = -1;

    for (i = max - 1; i >= 0; i--)
    {
        if (patient[i].patientNumber == 0) {
            addPatient = i;
        }
    }
    if (addPatient >= 0)
    {
        patient[addPatient].patientNumber = nextPatientNumber(patient, max);
        inputPatient(&patient[addPatient]);
        printf("*** New patient record added ***\n");
    }
    else
    {
        printf("ERROR: Patient listing is FULL!\n");
    }
    printf("\n");
}

// Edit a patient record from the patient array
// (Copy your code from MS#2)
void editPatient(struct Patient patient[], int max)
{
    int patientNum, find;

    printf("Enter the patient number: ");
    patientNum = inputIntPositive();
    find = findPatientIndexByPatientNum(patientNum, patient, max);
    printf("\n");

    if (find > 0)
    {
        menuPatientEdit(&patient[find]);
    }
    else
    {
        printf("\n");
        printf("ERROR: Patient record not found!\n");
    }
}

// Remove a patient record from the patient array
// (Copy your code from MS#2)
void removePatient(struct Patient patient[], int max)
{
    int patientNum, find;
    char characterSelect;

    printf("Enter the patient number: ");
    patientNum = inputIntPositive();
    find = findPatientIndexByPatientNum(patientNum, patient, max);
    if (find > 0)
    {

        printf("\n");
        displayPatientData(&patient[find], FMT_FORM);
        printf("\n");
        printf("Are you sure you want to remove this patient record? (y/n): ");
        characterSelect = inputCharOption("yn");
        if (characterSelect == 'y')
        {
            patient[find].patientNumber = 0;
            strncpy(patient[find].name, "", sizeof(patient[find].name));
            strncpy(patient[find].phone.number, "", sizeof(patient[find].phone.number));
            strncpy(patient[find].phone.description, "", sizeof(patient[find].phone.description));

            printf("Patient record has been removed!");
        }
        else if (characterSelect == 'n')
        {
            printf("Operation aborted.");
        }
        printf("\n\n");
    }
    else
    {
        printf("\n");
        printf("ERROR: Patient record not found!\n\n");
    }
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
void viewAllAppointments(struct ClinicData* data)
{
    int i, j;

    // Sorting data....... 
    sort(data->appointments, data->maxAppointments);

    displayScheduleTableHeader(NULL, 1);

    for (i = 0; i < data->maxAppointments; i++)
    {
        for (j = 0; j < data->maxPatient; j++)
        {
            if (data->appointments[i].patientNum && data->patients[j].patientNumber)
            {
                if (data->appointments[i].patientNum == data->patients[j].patientNumber)
                {
                    displayScheduleData(&data->patients[j], &data->appointments[i], 1);
                }
            }
        }
    }

    printf("\n");
}

// View appointment schedule for the user input date
void viewAppointmentSchedule(struct ClinicData* data)
{
    int dayEnd = 31;
    int i, j;
    struct Date date;

    printf("Year        : ");
    date.year = inputIntPositive();

    printf("Month (1-12): ");
    date.month = inputIntRange(1, 12);

    printf("Day (1-");
    if (date.month == 4 || date.month == 9 || date.month == 11)
    {
        dayEnd = 30;
    }
    if (date.month == 2)
    {
        dayEnd = 28;
    }
    if (date.year % 4 == 0 && date.month == 2)
    {
        dayEnd = 29;
    }

    printf("%d)  : ", dayEnd);
    date.day = inputIntRange(1, dayEnd);
    printf("\n");

    // Sorting data.........
    sort(data->appointments, data->maxAppointments);

    displayScheduleTableHeader(&date, 0);
    for (i = 0; i < data->maxAppointments; i++)
    {
        for (j = 0; j < data->maxPatient; j++)
        {
            if (data->appointments[i].patientNum && data->patients[j].patientNumber)
            {
                if (data->appointments[i].patientNum == data->patients[j].patientNumber)
                {
                    if (data->appointments[i].date.year == date.year && data->appointments[i].date.month == date.month && data->appointments[i].date.day == date.day)
                    {
                        displayScheduleData(&data->patients[j], &data->appointments[i], 0);
                    }
                }
            }
        }
    }
    printf("\n");
}


// Add an appointment record to the appointment array
void addAppointment(struct Appointment* appoint, int maxAppointments, struct Patient* patient, int maxPatients)
{
    struct Date date;
    struct Time time;
    int patientNum, index, dayEnd, i;
    int slotLoop = 1;

    printf("Patient Number: ");
    patientNum = inputIntPositive();
    index = findPatientIndexByPatientNum(patientNum, patient, maxPatients);
    if (index > 0)
    {
        do
        {
            slotLoop = 1;
            printf("Year        : ");
            date.year = inputIntPositive();

            printf("Month (%d-%d): ", FIRST_MONTH, FINAL_MONTH);
            date.month = inputIntRange(FIRST_MONTH, FINAL_MONTH);

            dayEnd = LeapYear(date.year, date.month);
            printf("Day (%d-%d)  : ", FIRST_MONTH, dayEnd);
            date.day = inputIntRange(FIRST_MONTH, dayEnd);

            time = getTime(date);  // getting appointment time

            for (i = 0; i < maxAppointments; i++)  // checking the timeslot
            {
                if ((date.year == appoint[i].date.year &&
                    date.month == appoint[i].date.month &&
                    date.day == appoint[i].date.day &&
                    time.hour == appoint[i].time.hour &&
                    time.minute == appoint[i].time.minute))
                {
                    slotLoop = 0;
                }
            }
            if (slotLoop == 0)
            {
                printf("\n");
                printf("ERROR: Appointment timeslot is not available!\n\n");
            }
        } while (slotLoop == 0);

        index = nextSlot(appoint, maxAppointments);
        appoint[index].date = date;
        appoint[index].time = time;
        appoint[index].patientNum = patientNum;
        printf("\n");
        printf("*** Appointment scheduled! ***\n");
    }
    else {
        printf("\n");
        printf("ERROR: Patient record not found!\n\n");
    }
    printf("\n");
}

// Remove an appointment record from the appointment array
void removeAppointment(struct Appointment* appoint, int maxAppointments, struct Patient* patient, int maxPatients)
{
    struct Date date;
    int patientNum, index, dayEnd, i, select;
    int loop = 0;

    printf("Patient Number: ");
    patientNum = inputIntPositive();

    index = findPatientIndexByPatientNum(patientNum, patient, maxPatients);  // find the index of patient
    if (index >= 0)
    {
        printf("Year        : ");
        date.year = inputIntPositive();

        printf("Month (%d-%d): ", FIRST_MONTH, FINAL_MONTH);
        date.month = inputIntRange(FIRST_MONTH, FINAL_MONTH);

        dayEnd = LeapYear(date.year, date.month);
        printf("Day (%d-%d)  : ", FIRST_MONTH, dayEnd);
        date.day = inputIntRange(FIRST_MONTH, dayEnd);

        for (i = 0; i < maxAppointments; i++)  // finding the appointment index
        {
            if ((appoint[i].patientNum == patientNum) &&
                (appoint[i].date.day == date.day) &&
                (appoint[i].date.month == date.month) &&
                (appoint[i].date.year == date.year))
            {
                loop = i;
            }
        }
        printf("\n");
        if (loop >= 0)
        {

            displayPatientData(&patient[index], FMT_FORM);
            printf("Are you sure you want to remove this appointment (y,n): ");

            select = inputCharOption("yn") == 'y';
            if (select)
            {
                appoint[loop].patientNum = 0;
                printf("\n");
                printf("Appointment record has been removed!\n\n");
            }

            else
            {
                printf("Canceled the Appointment Cancellation.\n\n");
            }
        }
    }
    else
    {
        printf("ERROR: Patient record not found!\n\n");
    }
}

//////////////////////////////////////
// ADDITIONAL FUNCTIONS
//////////////////////////////////////
// 
// Function to sort the values by using bubble sort method..........
void sort(struct Appointment appoints[], int max)
{
    int i, j;
    struct Appointment appointTemp;


    for (i = 0; i < max; i++)
    {
        appoints[i].time.minute = (appoints[i].date.year * 12 * 30 * 24 * 60) + (appoints[i].date.month * 30 * 24 * 60) + (appoints[i].date.day * 24 * 60) + (appoints[i].time.hour * 60) + appoints[i].time.minute;
    }

    for (i = max - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (appoints[j].time.minute > appoints[j + 1].time.minute)
            {
                appointTemp = appoints[j];
                appoints[j] = appoints[j + 1];
                appoints[j + 1] = appointTemp;
            }
        }
    }

    for (i = 0; i < max; i++)
    {
        appoints[i].time.minute = appoints[i].time.minute - (appoints[i].date.year * 12 * 30 * 24 * 60) - (appoints[i].date.month * 30 * 24 * 60) - (appoints[i].date.day * 24 * 60) - (appoints[i].time.hour * 60);
    }

}

// from here get the appointment time..........
struct Time getTime(struct Date date)
{
    struct Time time;
    int loopTime = 1;
    do
    {
        printf("Hour (%d-%d)  : ", START_HOUR_MIN, LAST_HOUR);
        time.hour = inputIntRange(START_HOUR_MIN, LAST_HOUR);

        printf("Minute (%d-%d): ", START_HOUR_MIN, LAST_MINUTE);
        time.minute = inputIntRange(START_HOUR_MIN, LAST_MINUTE);

        if ((time.hour < START_HOUR || time.hour > END_HOUR) || (time.hour == END_HOUR && time.minute > 0) || (time.minute % MINUTE_INTERVAL != 0))
        {
            printf("ERROR: Time must be between %02d:00 and %02d:00 in %02d minute intervals.\n\n", START_HOUR, END_HOUR, MINUTE_INTERVAL);
            loopTime = 0;
        }
        else
        {
            loopTime = 1;
        }
    } while (loopTime == 0);
    return time;
}

// For the next appointment slot........
int nextSlot(struct Appointment* app, int maxAppointments)
{
    int i = 0, slotFind = 0;
    while (i < maxAppointments && slotFind == 0)
    {
        if (app[i].patientNum < 1)
        {
            slotFind = 1;
        }
        i++;
    }
    return i;
}

//  Leap year
int LeapYear(int year, int month)
{
    int leapDate;
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        leapDate = 30;
    }
    else if (month == 2)
    {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            leapDate = 29;
        }
        else
        {
            leapDate = 28;
        }
    }
    else
    {
        leapDate = 31;
    }
    return leapDate;
}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (Copy your code from MS#2)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    int numPatient, find;
    printf("Search by patient number: ");
    numPatient = inputIntPositive();
    printf("\n");
    find = findPatientIndexByPatientNum(numPatient, patient, max);

    if (find >= 0)
    {
        displayPatientData(&patient[find], FMT_FORM);
    }
    else
    {
        printf("*** No records found ***\n");
    }
    printf("\n");
}

// Search and display patient records by phone number (tabular)
// (Copy your code from MS#2)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    int find = 0;
    int i;
    char phoneNum[PHONE_LEN + 1] = { '\0' };

    printf("Search by phone number: ");
    inputCString(phoneNum, 10, 10);
    printf("\n");
    displayPatientTableHeader();
    for (i = 0; i < max; i++)
    {

        if (strcmp(patient[i].phone.number, phoneNum) == 0)
        {
            displayPatientData(&patient[i], FMT_TABLE);
            find = 1;
        }
    }
    if (find == 0)
    {
        printf("\n");
        printf("*** No records found ***\n");
    }
    printf("\n");

}

// Get the next highest patient number
// (Copy your code from MS#2)
int nextPatientNumber(const struct Patient patient[], int max)
{
    int maxPatient, i;
    maxPatient = patient[0].patientNumber;

    for (i = 0; i < max; i++)
    {
        if (maxPatient < patient[i].patientNumber)
        {
            maxPatient = patient[i].patientNumber;
        }
    }
    return maxPatient + 1;
}

// Find the patient array index by patient number (returns -1 if not found)
// (Copy your code from MS#2)
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max)
{
    int i, loopNum = -1;
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber == patientNumber)
        {
            loopNum = i;
        }
    }
    return loopNum;
}

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (Copy your code from MS#2)
void inputPatient(struct Patient* patient)
{
    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\nName  : ", patient->patientNumber);

    inputCString(patient->name, 0, NAME_LEN); // call the function of inputCString.......
    printf("\n");
    inputPhoneData(&patient->phone);  // call the function of inputPhoneData........
}

// Get user input for phone contact information
// (Copy your code from MS#2)
void inputPhoneData(struct Phone* phone)
{
    int selection;
    printf("Phone Information\n"
        "-----------------\n"
        "How will the patient like to be contacted?\n"
        "1. Cell\n"
        "2. Home\n"
        "3. Work\n"
        "4. TBD\n"
        "Selection: ");
    selection = inputIntRange(1, 4);

    switch (selection)
    {
    case 1:
        strcpy(phone->description, "CELL");
        break;
    case 2:
        strcpy(phone->description, "HOME");
        break;
    case 3:
        strcpy(phone->description, "WORK");
        break;
    case 4:
        strcpy(phone->description, "TBD");
        break;
    default:
        break;
    }

    if (selection >= 1 && selection <= 3)
    {
        printf("\n");
        printf("Contact: %s\nNumber : ", phone->description);
        inputCStringNumExc(phone->number, 10, 10);
    }
    printf("\n");
}

//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
int importPatients(const char* fileData, struct Patient patients[], int max)
{
    int i = 0;
    FILE* fp = NULL;

    fp = fopen(fileData, "r");
    if (fp == NULL)
    {
        printf("Failed to open file\n");
    }
    else
    {
        while (i < max && fscanf(fp, " %d|%[^|]|%[^|]|%[^\n]\n", &patients[i].patientNumber,
            patients[i].name,
            patients[i].phone.description,
            patients[i].phone.number) != -1)
        {
            i++;
        }
        fclose(fp);
    }

    return i;
}

// Import appointment data from file into an Appointment array (returns # of records read)
int importAppointments(const char* fileData, struct Appointment appoint[], int max)
{
    int i = 0;
    FILE* fp = NULL;

    fp = fopen(fileData, "r");

    if (fp == NULL)
    {
        printf("Failed to open file\n");
    }
    else
    {
        while (i < max && fscanf(fp, "%d,%d,%d,%d,%d,%d", &appoint[i].patientNum,
            &appoint[i].date.year,
            &appoint[i].date.month,
            &appoint[i].date.day,
            &appoint[i].time.hour,
            &appoint[i].time.minute) != -1)
        {

            i++;

        }
        fclose(fp);
    }

    return i;
}
