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
### Name: get_site_country
#### File: [get_country.py](country/get_country.py)

We are using lambdas to connect and update the state in Postgres.

```mermaid
stateDiagram
direction  LR
  state branch <<choice>>
  Start --> QueryCount
  note left of QueryCount
    # of sites as "created"
  end note
  QueryCount --> branch
  branch --> country_assignation: count > 0
  note right of country_assignation
    Lambda
  end note
  branch --> End: count < 1
  country_assignation --> End
```

If the coordinates of the site are correct we put `get_country_processed` as state. Otherside we assign `get_country_failed`.


## DAG
### Dynamic Name: site_assignations_
#### File: [site_assignations_.py](more_assignations_/site_assignations_.py)

Next assignations tasks are AWS Lambdas functions

```mermaid
stateDiagram
direction  LR
  state branch <<choice>>
  Start --> QueryCount
  note left of QueryCount
    "get_country_processed"
  end note
  QueryCount --> branch
  branch --> ageb_assig: count > 0
  branch --> End: count < 1
  ageb_assig --> segment_assig
  note left of segment_assig
    Must have "AGEB"
  end note
  segment_assig --> metro_area_assig
  metro_area_assig --> End
```

As we can see each task (assignations) depends on the one before. That's why we use different states as follows:

```mermaid
flowchart LR
    subgraph First DAG -all countries-
	s(created) --> cF(get_country_failed)
	s --> cP(get_country_processed)
    end
    subgraph Second DAG -per country-
    cP --> aF(division_failed)
    cP --> aP(division_processed)
    aP --> sF(segment_failed)
    aP --> sP(segment_processed)
    sP --> mF(metro_area_failed)
    sP --> mP(metro_area_processed)
    end
    style cF fill:#000,color:#f00,stroke:#0f0
    style aF fill:#000,color:#f00,stroke:#0f0
    style sF fill:#000,color:#f00,stroke:#0f0
    style mF fill:#000,color:#f00,stroke:#0f0
    style mP fill:#000,color:#0f0,stroke:#0f0
```
