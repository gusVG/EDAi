###### Documentation Proposal 
# P44 Dashboard
With this DAG we want to update the dashboard that we present in Metabase.

## DAG
### Name: p44_dashboard
#### File: [dag_p44_dashboard.py](dag_p44_dashboard.py)

We are using XComs to send information between the tasks.

```mermaid
stateDiagram
direction  LR
  Start --> get_subscriptions
  get_subscriptions --> get_more_info_for_trips: Using XComs between all tasks
  get_more_info_for_trips --> merge_and_get_businesses_name
  merge_and_get_businesses_name --> get_teus_profit
  get_teus_profit --> check_mbl_and_write
  note right of check_mbl_and_write
    Writing on DB
  end note
  check_mbl_and_write --> End
```
