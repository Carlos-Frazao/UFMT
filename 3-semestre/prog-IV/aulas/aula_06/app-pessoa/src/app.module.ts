import { Module } from '@nestjs/common';
import { AppController } from './app.controller';
import { AppService } from './app.service';
import { DatabaseModule } from './database/database.module';
import { PessoaModule } from './pessoa/pessoa.module';

@Module({
  imports: [DatabaseModule, PessoaModule],
  controllers: [AppController],
  providers: [AppService],
})
export class AppModule {}
