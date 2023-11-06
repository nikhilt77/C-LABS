import java.util.Scanner;

class Employee {
    String name, address;
    int age, phone, salary;

    void printsalary() {
        System.out.println("Name: " + name);
        System.out.println("Salary: " + salary);
    }
}

class Officer extends Employee {
    String specialization;

    public Officer(int salary, String name, int phone, String specialization, int age) {
        this.name = name;
        this.salary = salary;
        this.phone = phone;
        this.specialization = specialization;
        this.age = age;
    }

    public void printDetails() {
        System.out.println("Officer: " + name);
        System.out.println("Specialization: " + specialization);
        super.printsalary();
    }
}

class Manager extends Employee {
    String department;

    public Manager(int salary, String name, int phone, String department, int age) {
        this.name = name;
        this.salary = salary;
        this.phone = phone;
        this.department = department;
        this.age = age;
    }

    void printsub() {
        System.out.println("Manager: " + name);
        System.out.println("Department: " + department);
        super.printsalary();
    }
}

public class Emp {
    public static void main(String[] args) {
        Scanner P = new Scanner(System.in);

        System.out.print("Enter name: ");
        String name = P.nextLine();
        System.out.print("Enter age: ");
        int age = P.nextInt();
        P.nextLine(); // Consume the newline
        System.out.print("Enter Phone: ");
        int phone = P.nextInt();
        P.nextLine(); // Consume the newline
        System.out.print("Enter salary: ");
        int salary = P.nextInt();
        P.nextLine(); // Consume the newline
        System.out.print("Enter Specialization: ");
        String specialization = P.nextLine();

        Officer officer = new Officer(salary, name, phone, specialization, age);

        System.out.print("Enter Manager name: ");
        String manname = P.nextLine();
        System.out.print("Enter age: ");
        int manage = P.nextInt();
        P.nextLine(); // Consume the newline
        System.out.print("Enter Phone: ");
        int manphone = P.nextInt();
        P.nextLine(); // Consume the newline
        System.out.print("Enter salary: ");
        int mansalary = P.nextInt();
        P.nextLine(); // Consume the newline
        System.out.print("Enter Department: ");
        String mandepartment = P.nextLine();

        Manager manager = new Manager(mansalary, manname, manphone, mandepartment, manage);

        System.out.println("Employee details: ");
        officer.printDetails();
        System.out.println();
        manager.printsub();

        P.close();
    }
}
