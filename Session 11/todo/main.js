function addTask() {
  e.preventDefault();
}

const form = document.querySelector("#form");
form.addEventListener("submit", (e) => {
  e.preventDefault();
  var task = document.getElementById("task").value;
  var task_new_item = document.createElement("li");
  task_new_item.innerHTML = task;
  var list = document.getElementById("new");
  list.appendChild(task_new_item);
  document.getElementById("task").value = "";
});
