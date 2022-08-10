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

We are using lambdas to connect and update the state in Postgres.

```mermaid
stateDiagram
direction  LR
  state branch <<choice>>
  Start --> QueryCount
  note left of QueryCount
    # of sites as "get_country_processed"
  end note
  QueryCount --> branch
  branch --> ageb_assignation: count > 0
  branch --> End: count < 1
  ageb_assignation --> segment_assignation
  note left of segment_assignation
    Must have "AGEB" to process
  end note
  segment_assignation --> metro_area_assignation
  metro_area_assignation --> End
```

If the coordinates of the site are correct we put `get_country_processed` as state othersite we assing `get_country_failed`.
