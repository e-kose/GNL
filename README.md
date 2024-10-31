# get_next_line
`Get_next_line`, bir dosya tanımlayıcısı `fd` ile belirtilen bir dosyadan bir satırı tamamen okuyan bir fonksiyondur. Bu fonksiyon, satırın içeriğini satır sonu karakteri ('\n') olmadan bir diziye atar ve line işaretçisini bu diziye yönlendirir.

Fonksiyona herhangi bir ayrılmış bellek geçirmemize gerek yoktur, sadece ayrılmış diziyi işaret edecek olan bir işaretçinin adresini geçmemiz yeterlidir. line, fonksiyon çağrısından sonra free() ile serbest bırakılabilir, aksi takdirde bir hata oluşmuştur.

Dosyayı read() ile art arda okuyarak işleyeceğiz ve bu fonksiyon dosya tanımlayıcısının dosyadaki pozisyonunu otomatik olarak ileriye taşır.

Önceki çağrılarda okunan verilere erişmek için bir statik işaretçi kullanmamız gerekecek.

Aşağıdaki durumları ele almalıyız:

Okuma tamponunda '\n' yoksa, önceki tamponla birleştirir ve read()'i tekrar çağırırız.
Okuma tamponunda '\n' varsa, önceki tamponla '\n' karakterine kadar birleştiririz.
Dosyanın sonuna ulaşırsak (read() == 0), önceki tamponla birleştiririz.
Son olarak, line işaretçisini, satırın tamamını içeren ve '\n' içermeyen ayrılmış bir diziye yönlendiririz. Ardından, ara dizilerde ayrılmış belleği serbest bırakır ve '\n' için 1 veya end_of_file için 0 döneriz.
Parametrelerde herhangi bir sorun varsa (BUFFER_SIZE <= 0) veya herhangi bir işlem sırasında bellek ayıramazsak, ayrılmış belleği serbest bırakır ve -1 döneriz.
