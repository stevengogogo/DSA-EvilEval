using Pkg
Pkg.activate("test/env")
Pkg.instantiate()

using Formatting

function solve_eq(string)
    return eval(Meta.parse(string))
end




function main(input_fn, output_fn)

    eqs = readlines(input_fn; keep=true)

    open(output_fn, "w") do io
        for i in eachindex(eqs)
            @show eqs[i]
            if length(eqs[i]) > 1
                e = strip(eqs[i], ['\n'])
                sol = solve_eq(e)
                write(io, format(sol) )
                write(io, "\n")
            end

            if i>1
                if (eqs[i]=="\n") & (eqs[i-1]=="\n")
                    #write(io, "\n")
                end
            end

        end
    end 
end


main("test/data/input.txt", "test/data/output.txt")