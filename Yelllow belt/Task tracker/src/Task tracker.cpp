#include <iostream>
#include <map>
#include <tuple>
using namespace std;

enum class TaskStatus {
  NEW,
  IN_PROGRESS,
  TESTING,
  DONE
};

using TasksInfo = map<TaskStatus, int>;

TaskStatus NextStatus(TaskStatus s){
	if (s == TaskStatus::NEW) {return TaskStatus::IN_PROGRESS;}
	if (s == TaskStatus::IN_PROGRESS) {return TaskStatus::TESTING;}
	if (s == TaskStatus::TESTING) {return TaskStatus::DONE;}
}

/*
 TaskStatus Next(TaskStatus task_status) {
  return static_cast<TaskStatus>(static_cast<int>(task_status) + 1);
}
*/

class TeamTasks {
public:
  const TasksInfo& GetPersonTasksInfo(const string& person) const{
	  return persons.at(person);
  };

  void AddNewTask(const string& person){
	  persons[person][TaskStatus::NEW]++;
  };

  tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count){
	  if (persons.count(person) == 0 ){
		  TasksInfo e;
		  return make_tuple(e,e);}
	  else {
	  TasksInfo d = persons[person];
	  TasksInfo new_t;
      for(auto& [key, value] : d){
    	  if(key != TaskStatus::DONE){
			  int m = min(task_count, value);
			  persons[person][key] -= m;
			  new_t[NextStatus(key)] = m;
			  if (m == value) {
				  persons[person].erase(key);
				  task_count -= m;
				  if (task_count == 0) {
				  	  break;
				  }
			  } else {break;}
    	  }
      }
      int e = persons[person][TaskStatus::DONE];
      persons[person].erase(TaskStatus::DONE);
      tuple t(new_t, persons[person]);
      if (e != 0){persons[person][TaskStatus::DONE] = e;}
      for(auto& [key, value] : new_t){
    	  persons[person][key] += value;
      }
      return t;
	  }
  };
private:
  map<string, TasksInfo> persons;
};

int main() {
  return 0;
}
