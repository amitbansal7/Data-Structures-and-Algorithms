def mergeSort(xs :List[Int]): List[Int] = {
    val n = xs.length
    if(n <= 1) xs
    else{
        val (first, second) = xs.splitAt(n/2)
        def merge(xs:List[Int], ys:List[Int]): List[Int] = (xs, ys) match {
            case (Nil, ys) => ys
            case (xs, Nil) => xs
            case (x::xs, y::ys) => 
                if (x <= y)  x :: merge(xs,y :: ys)
                else y :: merge(x::xs, ys)
        }
        merge(mergeSort(first),mergeSort(second))
    }
}
println(mergeSort(6::5::4::3::2::1::Nil))
