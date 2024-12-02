-- addejans

WITH formatted_content AS (
    SELECT 
        content_id,
        content_text AS original_text,
        STRING_AGG(
            CASE 
                WHEN word LIKE '%-%' THEN
                    -- Split hyphenated words, capitalize each part, and rejoin
                    ARRAY_TO_STRING(ARRAY(
                        SELECT INITCAP(part) 
                        FROM UNNEST(string_to_array(word, '-')) AS part
                    ), '-')
                ELSE
                    -- Capitalize non-hyphenated words
                    INITCAP(word)
            END, ' ') AS converted_text
    FROM (
        SELECT 
            content_id,
            content_text,
            UNNEST(string_to_array(content_text, ' ')) AS word
        FROM user_content
    ) AS words
    GROUP BY content_id, content_text
)
SELECT content_id, original_text, converted_text
FROM formatted_content
ORDER BY content_id;