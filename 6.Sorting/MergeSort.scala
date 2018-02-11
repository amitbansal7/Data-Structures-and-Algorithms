def mergeSort[T](xs :List[T])(lt: (T, T) => Boolean): List[T] = {
    val n = xs.length
    if(n <= 1) xs
    else{
        val (first, second) = xs.splitAt(n/2)
        def merge(xs:List[T], ys:List[T]): List[T] = (xs, ys) match {
            case (Nil, ys) => ys
            case (xs, Nil) => xs
            case (x::xs, y::ys) => 
                if (lt(x, y))  x :: merge(xs,y :: ys)
                else y :: merge(x::xs, ys)
        }
        merge(mergeSort(first)(lt),mergeSort(second)(lt))
    }
}
println(mergeSort(6::5::4::3::2::1::Nil)((a:Int, b:Int)=> a<=b))
