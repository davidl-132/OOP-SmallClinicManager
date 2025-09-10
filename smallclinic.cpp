//Name: Ly Tran Gia Khang
//ID: 24110098
//Generated with assistance from ChatGPT.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
class Doctor;
class Appointment;
class Patient;
class ChronicPatient;
class Clinic;

// ==================== Doctor ====================
// Lớp Doctor lưu trữ thông tin về bác sĩ
class Doctor{
private:
    string name;       // Tên bác sĩ
    string ID;         // Mã số bác sĩ
    string specialty;  // Chuyên khoa
public:
    // Constructor: khởi tạo giá trị cho bác sĩ
    Doctor(string _name, string _ID, string _specialty){
        name = _name;
        ID = _ID;
        specialty = _specialty;
    }

    // Getter: lấy thông tin
    string getName(){return name;}
    string getID(){return ID;}
    string getSpecialty(){return specialty;}
    // Setter: cập nhật thông tin
    void setName(string _name){name = _name;}
    void setID(string _ID){ID = _ID;}
    void setSpecialty(string _specialty){specialty = _specialty;}

    // Hiển thị thông tin bác sĩ
    void displayInfo(){
        cout << "Doctor's Information:" << endl;
        cout << "Name: " << getName() << endl;
        cout << "ID: " << getID() << endl;
        cout << "Specialty: " << getSpecialty() << endl;
    }
};

// ==================== Patient ====================
// Lớp Patient lưu thông tin bệnh nhân và lịch sử khám bệnh
class Patient{
private:
    string name;                  // Tên bệnh nhân
    string ID;                    // Mã bệnh nhân
    int age;                      // Tuổi
    vector<string> medicalHistory;// Lịch sử khám bệnh
public:
    // Constructor
    Patient(string _name, string _ID, int _age){
        name = _name;
        ID = _ID;
        age = _age;
    }

    // Getter
    string getName(){return name;}
    string getID(){return ID;}
    int getAge(){return age;}
    // Setter
    void setName(string _name){name = _name;}
    void setID(string _ID){ID = _ID;}
    void setAge(int _age){age = _age;}

    // Hiển thị thông tin bệnh nhân
    void displayInfo(){
        cout << "Patient's Information:" << endl;
        cout << "Name: " << getName() << endl;
        cout << "ID: " << getID() << endl;
        cout << "Age: " << getAge() << endl;
    }

    // Thêm một bản ghi mới vào lịch sử
    void addHistory(string _history){
        medicalHistory.push_back(_history);
    }

    // Xóa bản ghi trong lịch sử
    void removeHistory(string record){
        for (auto it = medicalHistory.begin(); it != medicalHistory.end(); ++it){
            if (*it == record){
                medicalHistory.erase(it);
                break;
            }
        }
    }

    // Hiển thị toàn bộ lịch sử khám bệnh
    void showHistory(){
        cout << "========== Medical history of " << getName() << " (ID: " << getID() << ") ==========" << endl;
        if(medicalHistory.empty()) cout << "No record found...!" << endl;
        else{
            for(int i=0; i < medicalHistory.size(); i++)
                cout << "#" << i+1 << ". " << medicalHistory[i] << endl;
        }
    }

    // Đặt lịch hẹn cho bệnh nhân (cơ bản)
    virtual void scheduleAppointment(string appID, string date, string time, string reason){
        cout << "Patient " << getName() << " scheduled appointment on " << date << " at " << time << " for " << reason << "." << endl;
        addHistory(date + " - " + time + ": " + reason);
    }

    // Destructor ảo
    virtual ~Patient(){}
};

// ==================== Chronic Patient ====================
// Lớp ChronicPatient kế thừa Patient, dành cho bệnh nhân mãn tính
class ChronicPatient : public Patient{
private:
    string conditionType; // Loại bệnh mãn tính
    string lastCheckup;   // Lần khám gần nhất
public:
    // Constructor
    ChronicPatient(string _name, string _ID, int _age, string _conditionType, string _lastCheckup) 
    : Patient(_name, _ID, _age){
        conditionType = _conditionType;
        lastCheckup = _lastCheckup;
    }

    // Getter
    string getConditionType(){return conditionType;}
    string getLastCheckup(){return lastCheckup;}
    // Setter
    void setConditionType(string _conditionType){conditionType = _conditionType;}
    void setLastCheckup(string _lastCheckup){lastCheckup = _lastCheckup;}

    // Đặt lịch hẹn cho bệnh nhân mãn tính (ghi chú thêm)
    void scheduleAppointment(string appID, string date, string time, string reason) override{
        cout << "Chronic patient requires regular check-up...!" << endl;
        cout << "Appointment set on " << date << " at " << time << " for " << reason << " (Condition: " << conditionType << ")." << endl;
        addHistory(date + " - " + time + ": " + reason + " [Chronic]");
    }
};

// ==================== Appointment ====================
// Lớp Appointment lưu thông tin về một cuộc hẹn
class Appointment{
private:
    string appID;    // Mã số hẹn
    string date;     // Ngày hẹn
    string time;     // Giờ hẹn
    string reason;   // Lý do khám
    string status;   // Trạng thái (Scheduled / Cancelled / Completed)
    Doctor *doctor;  // Bác sĩ phụ trách
    Patient *patient;// Bệnh nhân
public:
    // Constructor
    Appointment(string _appID, string _date, string _time, string _reason, string _status, Doctor *_doctor, Patient *_patient){
        appID = _appID;
        date = _date;
        time = _time;
        reason = _reason;
        doctor = _doctor;
        patient = _patient;
        status = "Scheduled";
    }

    // Getter
    string getAppID(){return appID;}
    string getDate(){return date;}
    string getTime(){return time;}
    string getReason(){return reason;}
    string getStatus(){return status;}
    Patient *getPatient(){return patient;}
    Doctor *getDoctor(){return doctor;}
    // Setter
    void setAppID(string _appID){appID = _appID;}
    void setDate(string _date){date = _date;}
    void setTime(string _time){time = _time;}
    void setReason(string _reason){reason = _reason;}
    void updateStatus(string _status){status = _status;}

    // Cập nhật trạng thái hủy lịch
    void cancel(){status = "Cancelled";}
    // Cập nhật trạng thái hoàn thành lịch hẹn
    void complete(){status = "Completed";}

    // Hiển thị thông tin chi tiết của lịch hẹn
    void displayInfo(){
        cout << "Appointment " << getAppID() << " on " << getDate() << " at " << getTime() << ":" << endl;
        cout << "Doctor: " << doctor->getName() << endl;
        cout << "Patient: " << patient->getName() << endl;
        cout << "Reason: " << getReason() << endl;
        cout << "[Status: " << getStatus() << "]" << endl;
    }
};

// ==================== Clinic ====================
// Lớp Clinic quản lý danh sách bệnh nhân, bác sĩ và lịch hẹn
class Clinic{
private:
    vector<Patient *> patients;       // Danh sách bệnh nhân
    vector<Doctor *> doctors;         // Danh sách bác sĩ
    vector<Appointment *> appointments;// Danh sách lịch hẹn
public:
    // Thêm đối tượng vào danh sách
    void addPatient(Patient *_patient){patients.push_back(_patient);}
    void addDoctor(Doctor *_doctor){doctors.push_back(_doctor);}
    void addAppointment(Appointment *_appointment){appointments.push_back(_appointment);} 

    // Hiển thị toàn bộ lịch hẹn
    void displayAppointmentList(){
        cout << endl << "========== Appointments List ==========" << endl;
        for(int i=0; i<appointments.size(); i++) {
            cout << "#" << i+1 << ". "; 
            appointments[i]->displayInfo();
            cout << endl;
        }
    }

    // Hiển thị danh sách bệnh nhân
    void displayPatientList(){
        cout << endl << "========== Patients List ==========" << endl;
        for(int i=0; i<patients.size(); i++) {
            cout << "#" << i+1 << ". ";
            patients[i]->displayInfo();
            cout << endl;
        }
    }

    // Hiển thị danh sách bác sĩ
    void displayDoctorList(){
        cout << endl << "========== Doctors List ==========" << endl;
        for(int i=0; i<doctors.size(); i++) {
            cout << "#" << i+1 << ". ";
            doctors[i]->displayInfo();
            cout << endl;
        }
    }

    // Chọn lịch hẹn theo số thứ tự
    Appointment* chooseAppointment(int i){
        if(i < 1 || i > appointments.size()) return 0;
        return appointments[i-1];
    }

    // Chọn bệnh nhân theo số thứ tự
    Patient* choosePatient(int i){
        if(i < 1 || i > patients.size()) return 0;
        return patients[i-1];
    }

    // Chọn bác sĩ theo số thứ tự
    Doctor* chooseDoctor(int i){
        if(i < 1 || i > doctors.size()) return 0;
        return doctors[i-1];
    }

    bool scheduleConflict(Doctor *doctor, string _date, string _time){ 
        for (int i = 0; i < appointments.size(); i++){ 
            Appointment *a = appointments[i]; 
            if (a->getDoctor() == doctor && 
                a->getDate() == _date && 
                a->getTime() == _time && 
                a->getStatus() == "Scheduled"){ 
                    return true; 
                } 
        } return false; 
    }

    // Destructor: giải phóng bộ nhớ cấp phát động
    ~Clinic(){
        for(int i=0; i < patients.size(); i++) delete patients[i];
        for(int i=0; i < doctors.size(); i++) delete doctors[i];
        for(int i=0; i < appointments.size(); i++) delete appointments[i];
    }
};

// Hàm tạo mã lịch hẹn ngẫu nhiên
string generateAppID() {
    int num = rand() % 1000; // random từ 0 → 999
    stringstream ss;
    ss << "APP" << setw(3) << setfill('0') << num; 
    return ss.str();
}

// Hàm menu hiển thị lựa chọn cho người dùng
void menu(){
    cout << "========== Clinic Manager ==========" << endl;
    cout << "1. Register the patient" << endl;
    cout << "2. Register the doctor" << endl;
    cout << "3. Schedule the appointment" << endl;
    cout << "4. Cancel the appointment" << endl;
    cout << "5. Attend the appointment" << endl;
    cout << "6. Check the medical history" << endl;
    cout << "7. Show the Doctors' list" << endl;
    cout << "8. Show the Patients' list" << endl;
    cout << "9. Show the Appointments' list" << endl;
    cout << "0. Exit the Clinic Manager" << endl;
    cout << "====================================" << endl;
    cout << "Choose your choice: ";

}

int main(){
    Clinic clinic;   // Đối tượng quản lý phòng khám
    int choice;

    // Khởi tạo sẵn một số bệnh nhân và bác sĩ
    Patient *p1 = new Patient("Nguyen Van A", "BN001", 25);
    Patient *p2 = new Patient("Tran Van B", "BN002", 28);
    ChronicPatient *p3 = new ChronicPatient("Le Van C", "BN003", 55, "Diabetes", "9-9-2025");

    Doctor *d1 = new Doctor("Le Van X", "DR001", "Cardiology");
    Doctor *d2 = new Doctor("Tran Thi Y", "DR002", "Chiropractic");

    clinic.addPatient(p1);
    clinic.addPatient(p2);
    clinic.addPatient(p3);
    clinic.addDoctor(d1);
    clinic.addDoctor(d2);

    // Vòng lặp menu chính
    while(true){
        menu();
        cin >> choice;
        cin.ignore();

        // OPTION 1: đăng ký bệnh nhân
        if(choice == 1){
            int choice1;
            cout << "Choose your type of patient: " << endl;
            cout << "\t#1. Regular patient" << endl;
            cout << "\t#2. Chronic patient" << endl;
            cout << "Choose your option: "; 
            cin >> choice1;
            cin.ignore();
            
            if(choice1 == 1){
                string _name, _ID;
                int _age;
                cout <<"Enter your name: "; getline(cin,_name);
                cout <<"Enter your ID: "; getline(cin,_ID);
                cout <<"Enter your age: ";
                while (!(cin >> _age) || _age < 0){ // kiểm tra nhập đúng số nguyên dương
                    cout << "Invalid input...!!! Please enter a non-negative number: ";
                    cin.clear();
                    cin.ignore(10000,'\n');
                }
                cin.ignore();
                Patient *p4 = new Patient(_name,_ID,_age);
                clinic.addPatient(p4);
                cout << "Register successfully...!" << endl;
            } else if(choice1 == 2){
                string _name, _ID, _ct, _lc;
                int _age;
                cout <<"Enter your name: "; getline(cin,_name);
                cout <<"Enter your ID: "; getline(cin,_ID);
                cout <<"Enter your age: ";
                while (!(cin >> _age) || _age < 0){
                    cout << "Invalid input...!!! Please enter a non-negative number: ";
                    cin.clear();
                    cin.ignore(10000,'\n');
                }
                cin.ignore();
                cout <<"Enter your condition type (e.g., Diabetes): "; getline(cin,_ct);
                cout <<"Enter your last check-up date: "; getline(cin,_lc);
                ChronicPatient *p5 = new ChronicPatient(_name, _ID, _age, _ct, _lc);
                clinic.addPatient(p5);
                cout << "Register successfully...!" << endl;
            }
        }

        // OPTION 2: đăng ký bác sĩ
        else if(choice == 2){
            string _name, _ID, _specialty;
            cout <<"Enter your name: "; getline(cin,_name);
            cout <<"Enter your ID: "; getline(cin,_ID);
            cout <<"Enter your specialty: "; getline(cin,_specialty);
            Doctor *d3 = new Doctor(_name, _ID, _specialty);
            clinic.addDoctor(d3);
            cout << "Register successfully...!" << endl;
        }

        // OPTION 3: đặt lịch hẹn
        else if(choice == 3){
            string _appID, _date, _time, _reason, _status;
            cout <<"Enter the date: "; getline(cin,_date);
            cout <<"Enter the time: "; getline(cin,_time);
            cout <<"Enter the reason: "; getline(cin,_reason);
            _status = "Scheduled";
            _appID = generateAppID();

            cout << "Choose the patient will attend the appointment: " << endl;
            clinic.displayPatientList();
            cout << "Enter the number: ";
            int pChoice; cin >> pChoice; cin.ignore();
            Patient *chosenPatient = clinic.choosePatient(pChoice);
            if(!chosenPatient){
                cout << "Invalid patient choice...!" << endl;
                continue;
            }

            cout << "Choose the doctor will examine the patient: " << endl;
            clinic.displayDoctorList();
            cout << "Enter the number: ";
            int dChoice; cin >> dChoice; cin.ignore();
            Doctor *chosenDoctor = clinic.chooseDoctor(dChoice);
            if(!chosenDoctor){
                cout << "Invalid doctor choice...!" << endl;
                continue;
            }

            if(clinic.scheduleConflict(chosenDoctor, _date, _time)){
                cout << "Appointment conflict...! The doctor is already has a schedule on " << _date << " at " << _time << ". Please choose another time or choose another doctor to schedule an appointment...!" << endl;
                continue;
            }

            Appointment *appoint = new Appointment(_appID, _date, _time, _reason, _status, chosenDoctor, chosenPatient);
            clinic.addAppointment(appoint);
            chosenPatient->scheduleAppointment(_appID, _date, _time, _reason);
            cout << "Appointment scheduled successfully...!" << endl;
        }

        // OPTION 4: hủy lịch hẹn
        else if(choice == 4){
            cout << "Choose the appointment you want to cancel: " << endl;
            clinic.displayAppointmentList();
            cout << "Enter the number: ";
            int aChoice; cin >> aChoice; cin.ignore();
            Appointment *chosenAppointment = clinic.chooseAppointment(aChoice);
            if(!chosenAppointment){
                cout << "Invalid appointment choice...!" << endl;
                continue;
            }
            
            chosenAppointment->cancel();
            string record = chosenAppointment->getDate() + " - " + chosenAppointment->getTime() + ": " + chosenAppointment->getReason();
            chosenAppointment->getPatient()->removeHistory(record);
            cout << "Appointment " << chosenAppointment->getAppID() << " has been cancelled successfully...!" << endl;
        }

        // OPTION 5: tham dự lịch hẹn
        else if(choice == 5){
            cout << "Choose the appointment you want to attend: " << endl;
            clinic.displayAppointmentList();
            cout << "Enter the number: ";
            int aChoice; cin >> aChoice; cin.ignore();
            Appointment *chosenAppointment = clinic.chooseAppointment(aChoice);
            if(!chosenAppointment){
                cout << "Invalid appointment choice...!" << endl;
                continue;
            }
            
            chosenAppointment->complete();
            cout << "Appointment " << chosenAppointment->getAppID() << " has been completed successfully...!" << endl;
        }

        // OPTION 6: xem lịch sử bệnh án
        else if(choice == 6){
            cout <<"Choose the patient you want to check the medical history: ";
            clinic.displayPatientList();
            cout <<"Enter the number: ";
            int pChoice; cin >> pChoice; cin.ignore();
            Patient *chosenPatient = clinic.choosePatient(pChoice);
            if(!chosenPatient){
                cout << "Invalid patient choice...!" << endl;
                continue;
            }
            chosenPatient->showHistory();
        }

        // OPTION 7: hiển thị danh sách bác sĩ
        else if(choice == 7){
            clinic.displayDoctorList();
        }

        // OPTION 8: hiển thị danh sách bệnh nhân
        else if(choice == 8){
            clinic.displayPatientList();
        }

        //OPTION 9: hiển thị danh sách các cuộc hẹn
        else if(choice == 9){
            clinic.displayAppointmentList();
        }

        // OPTION 0: thoát chương trình
        else if(choice == 0){
            cout << "Have a nice day <3...!" << endl;
            break;
        }

        // Lựa chọn không hợp lệ
        else {
            cout << "Inappropriate choice, please try again!" << endl;
        }

        system("pause"); // dừng màn hình (Windows)
        system("cls");   // xóa màn hình (Windows)
    }

}   