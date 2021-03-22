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


//Instead QDate
struct QDate {

};


class Worker
{
public:
	Worker(size_t id, string fullName, EPost post) : id(id), fullName(fullName), post(post) {

	}

	bool operator==(const Worker& wComp) {
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
};


class ProdTape {
public:
	ProdTape(size_t id, string name) : id(id), name(name) {

	}

	void AddWorker(const Worker& worker) {
		workers.push_back(worker);
		//Need to remove from freeWorkers, but on the higher lvl
	}

	bool RemoveWorker(Worker& worker) {
		//HACK: Maybe we should write special func remove for vector, because it can be used in many cases
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

	const vector<Worker>& GetWorkers() {
		return workers;
	}

	size_t CountWorkers() {

	}
private:
	size_t id;
	string name;
	vector<Worker> workers;
};


class FreeWorkers {
public:
	void Add(Worker worker) {
		workers.push_back(worker);
	}

	bool RemoveWorker(Worker& worker) {
		//HACK: Maybe we should write special func remove for vector, because it can be used in many cases
		auto it = find(workers.begin(), workers.end(), worker);

		if (it != workers.end()) {
			workers.erase(it);
			return true;
		}

		return false;
	}

	size_t CountWorkers() {

	}

protected:
	vector<Worker> workers;
};


class DataFreeWorkers : FreeWorkers {
public:
	DataFreeWorkers(QDate date, EShiftNum shift) {
		//HACK: Fills mass workers on current shift and date from DB
	}
};


class TestFreeWorkers : FreeWorkers {
	TestFreeWorkers(QDate date, EShiftNum shift) {
		//HACK: Fills mass workers by test values
	}
};


class StorageSingleton {
public:
	StorageSingleton(StorageSingleton& other) = delete;
	void operator=(const StorageSingleton&) = delete;

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

protected:
	StorageSingleton(QDate date, EShiftNum shiftNum) : date(date), shiftNum(shiftNum) {

	}
	//Static objects will be deleted automatically in the end of the programm
	static StorageSingleton* pStorageSingleton_s;
	size_t idEntered;
	size_t idShiftLeader;
	static vector<ProdTape> tapes;
	FreeWorkers freeWorkers;
	QDate date;
	EShiftNum shiftNum;
};


class TestStorageSingleton : StorageSingleton {
public:
	TestStorageSingleton(TestStorageSingleton& other) = delete;
	void operator=(const TestStorageSingleton&) = delete;
	static StorageSingleton* GetInstance(QDate date, EShiftNum shiftNum);

private:
	TestStorageSingleton(QDate date, EShiftNum shiftNum) : StorageSingleton(date, shiftNum) {
		//Fills idShiftLeader, freeWorkers, tapes with test values(with help of test class versions) 
	}
};


class DataStorageSingleton : StorageSingleton {
public:
	DataStorageSingleton(DataStorageSingleton& other) = delete;
	void operator=(const DataStorageSingleton&) = delete;
	static StorageSingleton* GetInstance(QDate date, EShiftNum shiftNum);

private:
	DataStorageSingleton(QDate date, EShiftNum shiftNum) : StorageSingleton(date, shiftNum) {
		//Fills idShiftLeader, freeWorkers, tapes with DB values(with help of test class versions)
	}
};


StorageSingleton* StorageSingleton::pStorageSingleton_s = nullptr;

StorageSingleton* TestStorageSingleton::GetInstance(QDate date, EShiftNum shiftNum)
{
	if (pStorageSingleton_s == nullptr) {
		pStorageSingleton_s = new TestStorageSingleton(date, shiftNum);
	}
	return pStorageSingleton_s;
}

StorageSingleton* DataStorageSingleton::GetInstance(QDate date, EShiftNum shiftNum)
{
	if (pStorageSingleton_s == nullptr) {
		pStorageSingleton_s = new DataStorageSingleton(date, shiftNum);
	}
	return pStorageSingleton_s;
}

int main(void) {

	return 0;
}