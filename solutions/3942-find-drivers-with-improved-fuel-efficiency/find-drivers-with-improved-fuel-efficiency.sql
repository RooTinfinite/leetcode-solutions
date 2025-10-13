WITH stat AS (
    SELECT 
        driver_id, 
        SUM(CASE WHEN MONTH(trip_date) <= 6 THEN distance_km / fuel_consumed ELSE 0 END) AS frst_tot_fuel_ef,
        SUM(CASE WHEN MONTH(trip_date) <= 6 THEN 1 ELSE 0 END) AS frst_tot_trips,
        SUM(CASE WHEN MONTH(trip_date) > 6 THEN distance_km / fuel_consumed ELSE 0 END) AS sec_tot_fuel_ef,
        SUM(CASE WHEN MONTH(trip_date) > 6 THEN 1 ELSE 0 END) AS sec_tot_trips
    FROM trips
    GROUP BY driver_id
), summary AS (
    SELECT 
        stat.driver_id, 
        d.driver_name,
        stat.frst_tot_fuel_ef / NULLIF(stat.frst_tot_trips, 0) AS frst_half_avg,
        stat.sec_tot_fuel_ef / NULLIF(stat.sec_tot_trips, 0) AS sec_half_avg
    FROM stat
    INNER JOIN drivers d ON stat.driver_id = d.driver_id
    WHERE stat.frst_tot_trips IS NOT NULL 
      AND stat.sec_tot_trips IS NOT NULL
)

SELECT 
    driver_id, 
    driver_name,
    ROUND(frst_half_avg, 2) AS first_half_avg,
    ROUND(sec_half_avg, 2) AS second_half_avg,
    ROUND(sec_half_avg - frst_half_avg, 2) AS efficiency_improvement 
FROM summary
WHERE sec_half_avg > frst_half_avg
  AND frst_half_avg IS NOT NULL
  AND sec_half_avg IS NOT NULL
ORDER BY efficiency_improvement DESC, driver_name;