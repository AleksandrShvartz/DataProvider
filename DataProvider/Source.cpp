#include<string>
#include<vector>

using namespace std;

enum class  EShiftNum {
	I = 1,
	II,
	III,
	IV
};

enum class  EPost {
	WORKER,
	SHIFT_SUPERVISOR,
	PRODUCTION_MANAGER
};

enum class  EStatus {
	ONPLACE,
	NOTONPLACE
};

//Вместо QDate
struct QDate {

};

class Employee
{
public:
	Employee(size_t id, string fullName, EPost post) : id(id), fullName(fullName), post(post) {

	}

	bool operator==(const Employee& wComp) {
		if (wComp.id == id && wComp.fullName == fullName && wComp.post == post)
			return true;
		return false;
	}

	const size_t GetId() {
		return id;
	}

	const string& GetFullName() {
		return fullName;
	}

	const EPost  GetPost() {
		return post;
	}

private:
	size_t id;
	string fullName;
	EPost post;
	EStatus status;
};

class ProdTape {
public:
	ProdTape(size_t id, string name) : id(id), name(name) {

	}

	void AddWorker(const Employee& worker) {
		workers.push_back(worker);
		//Нужно убирать из свободных людей, но это на уровне выше
	}

	bool RemoveWorker(Employee& worker) {
		//HACK: Написать отдельно функцию remove для вектора и вызывать ее здесь
		auto it = find(workers.begin(), workers.end(), worker);

		if (it != workers.end()) {
			workers.erase(it);
			return true;
		}

		return false;
	}

	const size_t GetId() {
		return id;
	}

	const string& GetName() {
		return name;
	}

	const vector<Employee>& GetWorkers() {
		return workers;
	}

private:
	size_t id;
	string name;
	vector<Employee> workers;
};

class FreeWorkers {
public:
	void Add(Employee worker) {
		workers.push_back(worker);
	}

	bool RemoveWorker(Employee& worker) {
		//HACK: Написать отдельно функцию remove для вектора и вызывать ее здесь
		auto it = find(workers.begin(), workers.end(), worker);

		if (it != workers.end()) {
			workers.erase(it);
			return true;
		}

		return false;
	}

protected:
	vector<Employee> workers;
};

class DataFreeWorkers : FreeWorkers {
public:
	DataFreeWorkers(QDate date, EShiftNum shift) {
		//HACK: заполняем массив workers на выбранную смену и дату из БД
	}
};

class TestFreeWorkers : FreeWorkers {
	TestFreeWorkers(QDate date, EShiftNum shift) {
		//HACK: заполняем массив workers Какими тестовыми значениями
	}
};

class Storage {
public:
	Storage(QDate date, EShiftNum shiftNum) : date(date), shiftNum(shiftNum){

	}
	FreeWorkers GetFreeWorkers() {

	}

	const vector<ProdTape> GetTapes() {

	}

	const ProdTape GetTape(size_t id) {

	}

	void SetTapes(vector<ProdTape> newTapes) {

	}

	void SetTape(ProdTape newTape) {

	}

private:
	Employee entered;
	Employee shiftLeader;
	static vector<ProdTape> tapes;
	FreeWorkers freeWorkers;
	QDate date;
	EShiftNum shiftNum;
};

class TestStorage : Storage {
	TestStorage(QDate date, EShiftNum shiftNum, size_t idEntered) : Storage(date, shiftNum) {
		//Заполняет поля idShiftLeader, freeWorkers, tapes тестовыми данными(с помощью 
		//	их тестовых версий) 
	}
};

class DataStorage : Storage {
	DataStorage(QDate date, EShiftNum shiftNum, size_t idEntered) : Storage(date, shiftNum) {
		//Заполняет поля idShiftLeader, freeWorkers, tapes данными с БД(с помощью 
		//	их data версий)
	}
};

int main(void) {

	return 0;
}