# EDAi - Estructura de Datos y Algoritmos 1 - Facultad de Ingeniería, UNAM
Códigos de las diapositivas
#
Diapositivas: [bit.ly/EDA1GVG](https://bit.ly/EDA1GVG)

# Site assignations

With these two DAGs we assginate country, AGEB (or similar), segment(s) and metropolitan zone to new sites.

We want to know -for the pipeline- which assignation is occurring (running) step by step. This is the reason why we check in every step if exists a site to process with the state necessary.

```mermaid
stateDiagram
direction  LR
  state branch <<choice>>
  [*] --> CountSitesToProcess
  CountSitesToProcess --> branch
  branch --> DifferentSiteAssignations: count > 0
  branch --> [*]: count < 1
  DifferentSiteAssignations --> [*]
```

## DAG
### get_site_country
#### File: [get_country.py](country/get_country.py)

We are using lambdas to connect and update the state in Postgres.

```mermaid
stateDiagram
direction  LR
  state branch <<choice>>
  Start --> QueryCount
  note left of QueryCount
    # of sites with "created" as state
  end note
  QueryCount --> branch
  branch --> country_assignation: count > 0
  note right of country_assignation
    Lambda
  end note
  branch --> End: count < 1
  country_assignation --> End
```
