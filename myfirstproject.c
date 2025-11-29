#include <stdio.h>

struct Patient {
	int id;
	char name[50];
	int age;
	char gender[10];
	char disease[50];
	char doctor[50];   // doctor in charge
	int roomNumber;    // room number
	int admitted;      // 1 = admitted, 0 = discharged
};

struct Patient patients[100];
int count = 0;   // how many patients are stored

// Function to add a new patient
void addPatient() {
	if (count == 100) {
		printf("\nMaximum patient limit reached! Cannot add more.\n");
		return;
	}

	printf("\n--- Add Patient ---\n");
	printf("Enter ID: ");
	scanf("%d", &patients[count].id);

	printf("Enter Name (no spaces): ");
	scanf("%s", patients[count].name);

	printf("Enter Age: ");
	scanf("%d", &patients[count].age);

	printf("Enter Gender (Male/Female/Other): ");
	scanf("%s", patients[count].gender);

	printf("Enter Disease (no spaces): ");
	scanf("%s", patients[count].disease);

	printf("Enter Doctor Name (no spaces): ");
	scanf("%s", patients[count].doctor);

	printf("Enter Room Number (0 if not admitted): ");
	scanf("%d", &patients[count].roomNumber);

	if (patients[count].roomNumber == 0) {
		patients[count].admitted = 0;
	} else {
		patients[count].admitted = 1;
	}

	count++;
	printf("Patient added successfully!\n");
}

// Function to display all patients
void displayPatients() {
	if (count == 0) {
		printf("\nNo patient records to display.\n");
		return;
	}

	printf("\n--- Patient List ---\n");
	for (int i = 0; i < count; i++) {
		printf("\nPatient #%d\n", i + 1);
		printf("ID: %d\n", patients[i].id);
		printf("Name: %s\n", patients[i].name);
		printf("Age: %d\n", patients[i].age);
		printf("Gender: %s\n", patients[i].gender);
		printf("Disease: %s\n", patients[i].disease);
		printf("Doctor: %s\n", patients[i].doctor);
		printf("Room Number: %d\n", patients[i].roomNumber);
		if (patients[i].admitted == 1) {
			printf("Status: Admitted\n");
		} else {
			printf("Status: Discharged\n");
		}
	}
}

// Function to search patient by ID
void searchPatient() {
	int id, found = 0;
	printf("\n--- Search Patient ---\n");
	printf("Enter Patient ID to search: ");
	scanf("%d", &id);

	for (int i = 0; i < count; i++) {
		if (patients[i].id == id) {
			printf("\nPatient Found:\n");
			printf("ID: %d\n", patients[i].id);
			printf("Name: %s\n", patients[i].name);
			printf("Age: %d\n", patients[i].age);
			printf("Gender: %s\n", patients[i].gender);
			printf("Disease: %s\n", patients[i].disease);
			printf("Doctor: %s\n", patients[i].doctor);
			printf("Room Number: %d\n", patients[i].roomNumber);
			if (patients[i].admitted == 1) {
				printf("Status: Admitted\n");
			} else {
				printf("Status: Discharged\n");
			}
			found = 1;
			break;
		}
	}

	if (!found) {
		printf("No patient found with ID %d\n", id);
	}
}

// Function to update patient details by ID
void updatePatient() {
	int id, found = 0;
	printf("\n--- Update Patient ---\n");
	printf("Enter Patient ID to update: ");
	scanf("%d", &id);

	for (int i = 0; i < count; i++) {
		if (patients[i].id == id) {
			found = 1;
			printf("\nCurrent Details:\n");
			printf("ID: %d\n", patients[i].id);
			printf("Name: %s\n", patients[i].name);
			printf("Age: %d\n", patients[i].age);
			printf("Gender: %s\n", patients[i].gender);
			printf("Disease: %s\n", patients[i].disease);
			printf("Doctor: %s\n", patients[i].doctor);
			printf("Room Number: %d\n", patients[i].roomNumber);
			if (patients[i].admitted == 1) {
				printf("Status: Admitted\n");
			} else {
				printf("Status: Discharged\n");
			}

			printf("\nEnter New Details:\n");
			printf("Enter New Name (no spaces): ");
			scanf("%s", patients[i].name);

			printf("Enter New Age: ");
			scanf("%d", &patients[i].age);

			printf("Enter New Gender: ");
			scanf("%s", patients[i].gender);

			printf("Enter New Disease: ");
			scanf("%s", patients[i].disease);

			printf("Enter New Doctor Name: ");
			scanf("%s", patients[i].doctor);

			printf("Enter New Room Number (0 if not admitted): ");
			scanf("%d", &patients[i].roomNumber);

			if (patients[i].roomNumber == 0) {
				patients[i].admitted = 0;
			} else {
				patients[i].admitted = 1;
			}

			printf("\nPatient record updated successfully!\n");
			break;
		}
	}

	if (!found) {
		printf("No patient found with ID %d\n", id);
	}
}

// Function to delete a patient by ID
void deletePatient() {
	int id, found = 0;
	printf("\n--- Delete Patient ---\n");
	printf("Enter Patient ID to delete: ");
	scanf("%d", &id);

	for (int i = 0; i < count; i++) {
		if (patients[i].id == id) {
			found = 1;
			// Shift remaining elements to the left
			for (int j = i; j < count - 1; j++) {
				patients[j] = patients[j + 1];
			}
			count--;
			printf("Patient with ID %d deleted successfully.\n", id);
			break;
		}
	}

	if (!found) {
		printf("No patient found with ID %d\n", id);
	}
}

// Function to show basic statistics
void showStatistics() {
	if (count == 0) {
		printf("\nNo patients in the system. Statistics not available.\n");
		return;
	}

	int totalAge = 0;
	int maleCount = 0, femaleCount = 0, otherCount = 0;

	for (int i = 0; i < count; i++) {
		totalAge += patients[i].age;

		// Very simple gender counting (based on first letter)
		if (patients[i].gender[0] == 'M' || patients[i].gender[0] == 'm') {
			maleCount++;
		} else if (patients[i].gender[0] == 'F' || patients[i].gender[0] == 'f') {
			femaleCount++;
		} else {
			otherCount++;
		}
	}

	float averageAge = (float)totalAge / count;

	printf("\n--- Patient Statistics ---\n");
	printf("Total Patients: %d\n", count);
	printf("Average Age: %.2f\n", averageAge);
	printf("Male Patients: %d\n", maleCount);
	printf("Female Patients: %d\n", femaleCount);
	printf("Other Gender: %d\n", otherCount);
}

// Function to list only admitted patients
void listAdmittedPatients() {
	int found = 0;
	printf("\n--- Currently Admitted Patients ---\n");

	for (int i = 0; i < count; i++) {
		if (patients[i].admitted == 1) {
			found = 1;
			printf("\nID: %d\n", patients[i].id);
			printf("Name: %s\n", patients[i].name);
			printf("Disease: %s\n", patients[i].disease);
			printf("Doctor: %s\n", patients[i].doctor);
			printf("Room Number: %d\n", patients[i].roomNumber);
		}
	}

	if (!found) {
		printf("No patients are currently admitted.\n");
	}
}

// Function to discharge a patient (set admitted = 0)
void dischargePatient() {
	int id, found = 0;
	printf("\n--- Discharge Patient ---\n");
	printf("Enter Patient ID to discharge: ");
	scanf("%d", &id);

	for (int i = 0; i < count; i++) {
		if (patients[i].id == id) {
			found = 1;
			if (patients[i].admitted == 0) {
				printf("Patient with ID %d is already discharged.\n", id);
			} else {
				patients[i].admitted = 0;
				patients[i].roomNumber = 0;
				printf("Patient with ID %d discharged successfully.\n", id);
			}
			break;
		}
	}

	if (!found) {
		printf("No patient found with ID %d\n", id);
	}
}

int main() {
	int choice;

	do {
		printf("\n===== Hospital Management System =====\n");
		printf("1. Add Patient\n");
		printf("2. Display All Patients\n");
		printf("3. Search Patient by ID\n");
		printf("4. Update Patient by ID\n");
		printf("5. Delete Patient by ID\n");
		printf("6. Show Statistics\n");
		printf("7. List Admitted Patients\n");
		printf("8. Discharge Patient\n");
		printf("0. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch(choice) {
		case 1:
			addPatient();
			break;
		case 2:
			displayPatients();
			break;
		case 3:
			searchPatient();
			break;
		case 4:
			updatePatient();
			break;
		case 5:
			deletePatient();
			break;
		case 6:
			showStatistics();
			break;
		case 7:
			listAdmittedPatients();
			break;
		case 8:
			dischargePatient();
			break;
		case 0:
			printf("\nExiting program. Goodbye!\n");
			break;
		default:
			printf("\nInvalid choice! Please try again.\n");
		}

	} while (choice != 0);

	return 0;
}
