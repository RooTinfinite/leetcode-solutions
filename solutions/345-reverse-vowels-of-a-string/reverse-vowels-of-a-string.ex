defmodule Solution do

  @vowels ~c"aeiouAEIOU"
  @spec reverse_vowels(s :: String.t) :: String.t
  def reverse_vowels(s) do
    s
    |> find_vowels()
    |> substitute_vowels(s)    
  end
  
  defp substitute_vowels(vowels, text, acc \\ "")
  defp substitute_vowels([v | vowels], <<c, text::binary>>, acc) when c in @vowels do
    substitute_vowels(vowels, text, acc <> <<v>>)
  end
  defp substitute_vowels(vowels, <<c, text::binary>>, acc) do
    substitute_vowels(vowels, text, acc <> <<c>>)
  end
  defp substitute_vowels( _, _, acc) do
    acc
  end

  defp find_vowels(text, vowels \\ [])
  defp find_vowels(<<v, text::binary>>, vowels) when v in @vowels do
    find_vowels(text, [v | vowels])
  end
  defp find_vowels(<<_, text::binary>>, vowels)do
    find_vowels(text, vowels)
  end
  defp find_vowels(_, vowels) do
    vowels
  end
  
end