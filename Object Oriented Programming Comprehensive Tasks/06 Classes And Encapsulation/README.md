# 06 Classes And Encapsulation

## Files
- `BankAccountTransferFriendDemo.cpp`: Models bank accounts and uses a friend transfer function to move balance after account validation. It prints account state before/after transfer.
- `BusSeatReservationSystem.cpp`: Implements seat booking/cancel flow in a bus class, tracks seat occupancy, and updates static reservation counts. It behaves like a mini console booking system.
- `CarEngineCompositionDemo.cpp`: Composes `Engine` inside `Car` and prints combined vehicle-engine data. It demonstrates has-a relationship in class design.
- `CommitteeAggregationDemo.cpp`: Uses one class object through aggregation to represent linked record data. The main flow builds a record and outputs composed information.
- `ConstructorAndCopyConstructorDemo.cpp`: Shows default and copy constructor behavior by creating objects and duplicating state. Output confirms copied member values.
- `DateClassFormattedOutput.cpp`: Reads date values and prints them in formatted styles with month-name mapping/validation. It demonstrates encapsulated formatting logic.
- `DateClassWithMonthName.cpp`: Uses enum/switch-based day or month representation and prints readable labels. It highlights symbolic constants in class workflows.
- `DisciplinaryCommitteeAggregation.cpp`: Builds disciplinary records and optionally links academic warning history through aggregation. It collects inputs, evaluates decision, and prints final report.
- `EmployeeEncapsulationDemo.cpp`: Encapsulates employee-like fields behind setters/getters and displays controlled member access. It demonstrates private-data protection.
- `EmployeeFunctionOverloading.cpp`: Overloads employee setter/member functions with different parameter sets. It demonstrates same-function-name, different-signature behavior.
- `EngineInitializationListDemo.cpp`: Initializes members (including composite/dynamic structures) through constructor initializer lists. It demonstrates cleaner object initialization order.
- `FriendClassAccessDemo.cpp`: Uses a friend class to modify/read private data of another class. It demonstrates controlled breach of strict encapsulation.
- `FriendFunctionEventCard.cpp`: Uses a friend function to access private event-card details for formatted output. It shows function-level friendship.
- `FriendTransferBankAccount.cpp`: Demonstrates friend-based account operations where helper logic accesses private balances directly. It models trusted cross-object operation.
- `PersonAddressAggregation.cpp`: Aggregates address object inside person object and prints combined identity/location data. It is a straightforward aggregation example.
- `PrivateMembersAccessorDemo.cpp`: Uses getters/setters and `this` disambiguation to manage private members. It demonstrates object-safe mutation and retrieval.
- `RoomAreaVolumeClass.cpp`: Encapsulates room dimensions and computes area/volume through class methods. The result is derived from stored dimensions.
- `RoomClassAreaVolumeV2.cpp`: Alternate room class version with constructor-driven initialization and geometric calculation output. It reinforces method-based computation.
- `StaticFunctionMemberDemo.cpp`: Demonstrates static data and static member functions shared across instances. Output shows class-level rather than object-level state.
- `StaticMembersThroughPointers.cpp`: Accesses class behavior via object pointers while tracking static/shared members. It contrasts pointer access with static storage.
- `StaticMemberWithObjectPointers.cpp`: Creates objects through pointers and observes static member count updates. It demonstrates shared counters across instances.
- `StudentAttendanceManager.cpp`: Manages student attendance data and computes class-level metrics through class methods. It models record update and summary retrieval.
- `StudentConstructorDestructorDemo.cpp`: Demonstrates constructor initialization and destructor invocation sequence with student objects. Output reflects lifecycle events.
- `StudentStaticCountTracker.cpp`: Tracks number of created student objects with a static counter. Each object creation changes shared count state.
- `StudentStaticObjectCounter.cpp`: Another static-count example where constructors increment a class-wide tally. It emphasizes persistent shared class data.
- `ThisPointerConstMethodDemo.cpp`: Uses `this` and const-qualified member functions to safely expose read-only state. It demonstrates const-correct interface design.
- `Vehicle Input Module/Vehicle.h`: Declares a compact `vehicle` type with model name and price fields used by the input demo.
- `Vehicle Input Module/VehicleDataInputDemo.cpp`: Takes vehicle model/price from user input and prints stored values. It verifies class field assignment through interactive input.

Total source files: 28
